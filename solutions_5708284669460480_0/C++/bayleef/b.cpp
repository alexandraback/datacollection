#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

double d[110][110],p[110][110];
int T,ts;
int nx[110][30],mx[110][110];
int i,j,k,l,m,n;
int pf[300];
int u[30];
char s[300];
double ans;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for(ts=1;ts<=T;ts++)
	{
		scanf("%d%d%d",&k,&m,&n);
		scanf("%s",&s);
		memset(u,0,sizeof(u));
		for(i=0;s[i];i++)
			u[s[i]-'A']++;
		scanf("%s",&s);
		s[m]='$';
		for(i=m+1;i<=2*m;i++)
			s[i]=s[i-m-1];
		s[i]=0;
		for(i=0;i<=2*m;i++)
		{
			for(j=i;j && s[i]!=s[pf[j-1]];j=pf[j-1]);
			pf[i]=j?pf[j-1]+1:0;
		}
		for(i=m;i>=0;i--)
			for(s[m+i+1]='A';s[m+i+1]<='Z';s[m+i+1]++)
			{
				for(j=m+i+1;j && s[m+i+1]!=s[pf[j-1]];j=pf[j-1]);
				nx[i][s[m+i+1]-'A']=j?pf[j-1]+1:0;
			}
		for(j=0;j<=m;j++)
		{
			p[0][j]=!j;
			d[0][j]=0;
			mx[0][j]=j?-1:0;
		}
		for(i=1;i<=n;i++)
			for(j=0;j<=m;j++)
			{
				p[i][j]=d[i][j]=0;
				mx[i][j]=-1;
			}
		for(i=0;i<=n;i++)
			for(j=0;j<=m;j++)
			{
				if(p[i][j]!=0.0)
					d[i][j]/=p[i][j];
				for(l=0;l<26;l++)
					if(u[l])
					{
						p[i+1][nx[j][l]]+=p[i][j]*u[l]/k;
						d[i+1][nx[j][l]]+=(d[i][j]+(nx[j][l]==m))*p[i][j]*u[l]/k;
						if(mx[i][j]>=0)
							mx[i+1][nx[j][l]]=max(mx[i+1][nx[j][l]],mx[i][j]+(nx[j][l]==m));
					}
			}
		ans=0;
		for(j=0;j<=m;j++)
			if(ans<mx[n][j])
				ans=mx[n][j];
		for(j=0;j<=m;j++)
			ans-=d[n][j]*p[n][j];
		printf("Case #%d: %.12lf\n",ts,ans);
	}
	return 0;
}