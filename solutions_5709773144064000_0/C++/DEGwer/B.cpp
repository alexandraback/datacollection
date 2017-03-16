#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	FILE *fr=fopen("B-small-attempt0.in","r");
	FILE *fw=fopen("out1.txt","w");
	int data;
	fscanf(fr,"%d",&data);
	for(int p=0;p<data;p++)
	{
		double cst,prd,mok;
		fscanf(fr,"%lf%lf%lf",&cst,&prd,&mok);
		double now=2.0,tim=0.0;
		double mini=1000000000000000000000000000000000.0;
		for(;;)
		{
			if(mini>=tim+mok/now)
			{
				mini=tim+mok/now;
			}
			else
			{
				break;
			}
			tim+=cst/now;
			now+=prd;
		}
		fprintf(fw,"Case #%d: %.10lf\n",p+1,mini);
	}
}