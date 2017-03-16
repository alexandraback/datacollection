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
char name[1000002];
long long l[100002];
long long n[100002];
long long r[100002];
bool isCon(char c)
{
	return c!='a' && c!='e' &&c!='i' &&c!='o' &&c!='u';
}
int main()
{
	int T,N,X,Y;
	scanf("%d",&T);

	for (int cs=1;cs<=T;cs++)
	{
		scanf("%s%d",name,&N);
		int len  = strlen(name);
		long long ans = 0;
		int num = 0;
		int last = -1;
		for (int i=0;i<len;)
		{
			if (isCon(name[i]))
			{
				int cnt = 0;
				while(i<len && isCon(name[i]))
				{
					i++;
					cnt++;
				}
				if (cnt>=N)
				{
					if (last==-1)
					{						
						l[num]=i-cnt;
						n[num]=cnt;
						last = i;
					}
					else
					{
						r[num]=i-cnt+N-1-last;
						num++;		
						l[num]=i-cnt;
						n[num]=cnt;
						last = i;
					}
				}
			}
			else
				i++;
		}
		if (last != -1)
		{			
			r[num]=len-last;
			num++;
		}
		for (int i=0;i<num;i++)
		{
			ans += (l[i]+1)*(n[i]-N);
			ans += (r[i]+1)*(n[i]-N);
			ans += (l[i]+1)*(r[i]+1);
			if (n[i]>N+1)
				ans += (n[i]-N)*(n[i]-1-N)/2;
		}
		printf("Case #%d: %lld\n",cs,ans);
	}
	return 0;
}