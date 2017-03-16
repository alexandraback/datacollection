#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d",&t);
	for(int testCase=1;testCase<=t;testCase++)
		{
			int a,b,k;
			scanf("%d%d%d",&a,&b,&k);
			int counter=0;
			for(int i=0;i<a;i++)
			{
				for(int j=0;j<b;j++)
				{
					if((i&j)<k)
						counter++;
				}
			}
				printf("Case #%d: %d\n",testCase,counter);
		}
		return 0;
}