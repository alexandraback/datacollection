#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	int T,N,X,Y;
	scanf("%d",&T);

	for (int cs=1;cs<=T;cs++)
	{
		scanf("%d%d",&X,&Y);
		printf("Case #%d: ",cs);
		if (X<0)
		{
			X = -X;
			for (int i=0;i<X;i++)
			{
				printf("EW");
			}
		}
		else
		{
			for (int i=0;i<X;i++)
			{
				printf("WE");
			}
		}
		if (Y<0)
		{
			Y = -Y;
			for (int i=0;i<Y;i++)
			{
				printf("NS");
			}
		}
		else
		{
			for (int i=0;i<Y;i++)
			{
				printf("SN");
			}
		}
		printf("\n");
	}
	return 0;
}