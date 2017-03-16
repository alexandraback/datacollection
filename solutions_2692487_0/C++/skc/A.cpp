// Codejam.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include <map>
#include <vector>
#include <iostream>

using namespace std;

typedef int typ;

#if 1

typ arr[100],pen[100]; 

int mysort(const void* p1, const void* p2)
{
	typ*  t1 = (typ*)p1;
	typ*  t2 = (typ*)p2;

	if(*t1 == *t2)		return 0;
	if(*t1 < *t2)		return -1;
	return 1;
}

int main(void)
{
	FILE* fin = fopen("Y:\\IO\\A1.in","r");
	freopen("Y:\\IO\\A.out", "w", stdout);

	int i,tst,n,j;
	typ a;
	fscanf(fin,"%d",&tst);
	for(i=1 ; i<=tst ; ++i)
	{
		fscanf(fin,"%d %d",&a, &n);
		memset(arr, 0, sizeof(typ)*n);
		memset(pen, 0, sizeof(typ)*n);

		for(j=0 ; j<n ; ++j)
			fscanf(fin,"%d ",&arr[j]);

		qsort(arr,n,sizeof(typ),mysort);

		int t=0, p=0, loc = -1;
#if 0
		for(j=0 ; j<n ; ++j)
		{
			if(arr[j] < a)
			{
				a += arr[j];
				continue;
			}
			// Need to add something
			typ aa = (a<<1)-1;
			if(arr[j] >= aa)
			{
				t += n-j;
				break;
			}
			t++;
			a = aa;
			a += arr[j];
		}
#else
		for(j=0 ; j<n ; ++j)
		{
			if(arr[j] < a)
			{
				a += arr[j];
//				if(p && !(--p)) 		loc = j;
				continue;
			}
			// Need to add something
			if(a==1)
			{
				t += n-j;
				goto LBL_RES;
			}

			do{
#if 0
				if(++p >= n-j)
				{
					t += n-j;
					goto LBL_RES;
				}
#endif
				if(++pen[j] >= n-j)
				{
					int k=0;
					for(k=j ; k<n ; ++k)
						pen[k] = -1;
					goto LBL_RES1;
				}
				a = (a<<1)-1;
			}while(arr[j] >= a);

			a += arr[j];
		}

// 2
// 2 5 100
// 1 1 0
LBL_RES1:
		int sum = 0;
		for(j=n-1 ; j>=0 ; --j)
		{
			if(pen[j]<0)	t++;
			else if(pen[j] > n-j-t)	{t++;}
			else
			{
				t+=pen[j];
			}

		}
LBL_RES:
#endif
		printf("Case #%d: %d\n",i, t);
	}

	fclose(fin);
	fflush(stdin);
	getchar();
	return 0;
}

#endif