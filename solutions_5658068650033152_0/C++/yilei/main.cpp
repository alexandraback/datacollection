#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>

#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

int main()
{
	int T,N,M,k;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		scanf("%d%d%d",&N, &M, &k);
		printf("Case #%d: ",i);
		if (N>M)
		{
			int tmp = N;
			N = M;
			M = tmp;
		}
		if (N==1 || N==2)
		{
			printf("%d\n", k);
		}
		else if (N==3)
		{
			if (M==3)
			{				
				if (k<5)
					printf("%d\n", k);
				else printf("%d\n", k-1);
			}
			else if (M==4)
			{				
				if (k<5)
					printf("%d\n", k);
				else if (k<8)
					printf("%d\n", k-1);
				else printf("%d\n", k-2);
			}
			else if (M==5)
			{
				if (k<5)
					printf("%d\n", k);
				else if (k<8)
					printf("%d\n", k-1);
				else if (k<11)				
					printf("%d\n", k-2);
				else printf("%d\n", k-3);
			}
			else if (M==6)
			{
				if (k<5)
					printf("%d\n", k);
				else if (k<8)
					printf("%d\n", k-1);
				else if (k<11)				
					printf("%d\n", k-2);
				else if (k<14)
					printf("%d\n", k-3);
				else
					printf("%d\n", k-4);
			}
		}
		else if (N==4)
		{
			if (M==4)
			{
				if (k<5)
					printf("%d\n", k);
				else if (k<8)
					printf("%d\n", k-1);
				else if (k<10)				
					printf("%d\n", k-2);
				else if (k<12)				
					printf("%d\n", k-3);
				else
					printf("%d\n", k-4);
			}
			else if (M==5)
			{
				if (k<5)
					printf("%d\n", k);
				else if (k<8)
					printf("%d\n", k-1);
				else if (k<10)				
					printf("%d\n", k-2);
				else if (k<12)				
					printf("%d\n", k-3);
				else if (k<14)				
					printf("%d\n", k-4);
				else if (k<16)				
					printf("%d\n", k-5);
				else
					printf("%d\n", k-6);
			}
		}		
	}
	return 0;
}