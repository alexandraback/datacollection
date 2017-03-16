//============================================================================
// Name        : google2012-1A2.cpp
// Author      : ezhache
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * 1A.cpp
 *
 *  Created on: Apr 28, 2012
 *      Author: ezhache
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void sort(int a[][3], int num)
{
	int tmp[2];
	for (int i=0;i<num;i++)
	{
		for(int j=i+1;j<num;j++)
		{
			if(a[i][1]>a[j][1])
			{
				tmp[0]=a[i][0];
				tmp[1]=a[i][1];
				a[i][0]=a[j][0];
				a[i][1]=a[j][1];
				a[j][0]=tmp[0];
				a[j][1]=tmp[1];
			}
		}
	}
};

int main() {
	int round=0;
	int level;
	int a[1000][3];
	int i,j,h,ka,kb;
	int currStar;
	cin >>round;
	for (i=1;i<=round;i++)
	{
		currStar=0;
		scanf("%d",&level);
		for(j=0;j<level;j++)
		{
			scanf("%d%d",&a[j][0],&a[j][1]);
			a[j][2]=0;
		}
		sort(a,level);
		ka=0;
		kb=0;
		for(j=0;;j++)
		{
			if(currStar>=a[kb][1])
			{
				if(a[kb][2]==0)
				{
					currStar+=2;
					a[kb][2]=2;
					kb++;
				}
				else if(a[kb][2]==1)
				{
					currStar+=1;
					a[kb][2]=2;
					kb++;
				}

			}
			else
			{
				for(h=level-1;h>=0;h--)
				{
					if(currStar>=a[h][0]&&a[h][2]==0)
					{
						currStar+=1;
						a[h][2]=1;
						break;
					}
				}
				if(h<0)
				{
					break;
				}
			}
			if(kb==level) break;

		}

		if(kb==level)
		{
			printf("Case #%d: %d\n",i,j+1);
		}
		else
		{
			printf("Case #%d: Too Bad\n",i);
		}
	}

	return 0;
}
