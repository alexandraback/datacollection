#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <utility>

#define MN 200
#define NEG -1

using namespace std;

int point[MN];

int main()
{
	int t, n, total;
	scanf("%d", &t);
	for(int c=1; c<=t; c++)
	{
		//
		total=0;
		//
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d", point+i);
			total+=point[i];
		}
		int share = total;
		int divide = n;
		bool success;
		double mean = 0;
		do
		{
			success=true;
			mean = (share+total)*1.0/divide;
			for(int i=0; i<n; i++)
				if(point[i]!=NEG && point[i]>=mean)
				{
					share-=point[i];
					divide--;
					success=false;
					point[i]=NEG;
				}
		}while(!success);

		printf("Case #%d:", c);
		for(int i=0; i<n; i++)
		{
			printf(" %lf", (point[i]!=NEG)?((mean-point[i])/total)*100:0);
		}
		puts("");
	}
	return 0;
}
