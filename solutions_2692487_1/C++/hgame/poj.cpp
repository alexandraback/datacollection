#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <set>
#include <complex>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
int b[100];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);
	int cas;
	scanf("%d",&cas);
	for(int cs=1;cs<=cas;cs++)
	{
		int a,n;
		scanf("%d",&a);
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",b+i);
		sort(b,b+n);
		if(a==1)
		{
			printf("Case #%d: %d\n",cs,n);
			continue;
		}
		int ans=100;
		int _ans=0;
		for(int i=0;i<n;i++)
		{
			if(a>b[i]) a+=b[i];
			else
			{
				ans=min(_ans+n-i,ans);
				while(a<=b[i])
				{
					_ans++;
					a+=a-1;
				}
				a+=b[i];
			}
		}
		ans=min(_ans,ans);
		printf("Case #%d: %d\n",cs,ans);
	}
}
