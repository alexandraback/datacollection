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
int a[100][100];
int main()
{
	int cas;
	freopen("B-large.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&cas);
	for(int cs=1;cs<=cas;cs++)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
		}
		printf("Case #%d: ",cs);
		bool ok=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				bool ok1=1;
				for(int k=0;k<n;k++)
				{
					if(a[k][j]>a[i][j]) {ok1=0; break;}
				}
				if(!ok1)
				{
					ok1=1;
					for(int k=0;k<m;k++)
					{
						if(a[i][k]>a[i][j]) {ok1=0; break;}
					}
				}
				if(!ok1) {ok=0; goto out;}
			}
		}
out:if(ok)  puts("YES");
	else puts("NO");
	}
}