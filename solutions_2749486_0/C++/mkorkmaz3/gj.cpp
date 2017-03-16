#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;



int main()
{

	assert(freopen("B-small-attempt0.in", "r", stdin));
	assert(freopen("output.out", "w", stdout));

	int nCase;

	scanf("%d",&nCase);

	int X,Y;
	
	
	for(int i = 0 ; i < nCase ; i++)
	{
		scanf("%d",&X);
		scanf("%d",&Y);
		int currentInd = 0;
		int j;
		printf("Case #%d: ",i+1);
		if(X < 0)
		{
			for(j = 0 ; j > X ; j--)
			{
				printf("EW");
			}
			if(Y < 0)
			{
				for(j = 0 ; j > Y ; j--)
				{
					printf("NS");
				}
			}
			else
			{
				for(j = 0 ; j < Y ; j++)
				{
					printf("SN");
				}
			}
		}
		else
		{
			for(j = 0 ; j < X ; j++)
			{
				printf("WE");
			}
			if(Y < 0)
			{
				for(j = 0 ; j > Y ; j--)
				{
					printf("NS");
				}
			}
			else
			{
				for(j = 0 ; j < Y ; j++)
				{
					printf("SN");
				}
			}
		}


		

		
		printf("\n");
	}
		

		

	
}