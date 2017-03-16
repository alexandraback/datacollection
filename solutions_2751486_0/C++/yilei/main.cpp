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
char name[100002];
int main()
{
	int T,N,X,Y;
	scanf("%d",&T);

	for (int cs=1;cs<=T;cs++)
	{
		scanf("%s%d",name,&N);
		int len  = strlen(name);
		long long ans = 0;
		for (int i=0;i<len;i++)
			for (int j=i;j<len;j++)
			{
				int cnt = 0;
				for (int k=i;k<=j;k++)
				{
					if (name[k]!='a' && name[k]!='e' &&name[k]!='i' &&name[k]!='o' &&name[k]!='u')
					{
						cnt++;
						if (cnt>=N)
						{
							ans++;
							break;
						}
					}
					else
						cnt = 0;
				}
			}
		printf("Case #%d: %d\n",cs,ans);
	}
	return 0;
}