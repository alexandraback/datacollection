/*
 * main.cpp
 *
 *  Created on: 2013-4-9
 *      Author: whd
 */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long big;
const int N=10202;
int v[N];
int n,e,r;
big f[N][120];
int main()
{
	int cass,cas,i,j,k;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&cas);
	for(cass=1;cass<=cas;cass++)
	{
		scanf("%d%d%d",&e,&r,&n);
		for(i=1;i<=n;i++)
			scanf("%d",&v[i]);
		memset(f,-127,sizeof(f));
		if(r>e)r=e;
		f[0][e-r]=0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=e;j++)
			{
				for(k=0;k<=e;k++)
					if(k+r-j>=0&&k+r<=e)
						f[i][j]=max(f[i][j],f[i-1][k]+1ll*(k+r-j)*v[i]);
			}
		}
		printf("Case #%d: %I64d\n",cass,f[n][0]);
	}
	return 0;
}
