#ifndef _WECATMULL_
#define _WECATMULL_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "weobject.h"

#define WE_ERR_FILE     -1
#define WE_ERR_OVERFLOW -2
#define WE_ERR_END_FILE	-3

/*
Routines to evaluate points through Catmull-rom splines
See more at: http://steve.hollasch.net/cgindex/curves/catmull-rom.html

All data is treated as 3D.
*/

typedef struct tagCatmullArray{
	WEVect3  *points;
	int	nPoints;
	int	currentPoint;
	float	currentEval;
}CatmullArray;


int weCatmullArrayCreate(CatmullArray *array,int nPoints);				//Create memory ofr array of "nPoints"
int weCatmullArrayDelete(CatmullArray *array);						//Delete Arrays
int weCatmullEval(float *p1,float *p2, float *p3, float *p4,float t, float *result); 	//Evaluate 4 points through "t"
int weCatmullEvalArray(CatmullArray *pointList,float step,float *result_cat);				//Evaluate an Array of points, automatically change segments  
int weCatmullArrayFromFile(char *filename,CatmullArray *arrayDest);			//Load a list of points from file
int weCatMullRewind(CatmullArray *array);

#endif

