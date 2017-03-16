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

vector<int>v[15];
int p10[10];
int i,j,k,x,T,ts;
char s[20];
long long n,m,ans;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	p10[0]=1;
	for(i=1;i<=7;i++)
		p10[i]=p10[i-1]*10;
	v[1].push_back(1);
	for(i=2;i<=14;i++)
	{
		v[i].resize(p10[i/2]);
		for(j=1+p10[i/2-1];j<p10[i/2];j++)
		{
			x=j;
			k=0;
			while(x)
			{
				k=k*10+x%10;
				x/=10;
			}
			v[i][j]=v[i-1].back()+k+p10[i/2];
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		if(n<20)
		{
			printf("Case #%d: %lld\n",++ts,n);
			continue;
		}
		n--;
		sprintf(s,"%lld",n);
		k=strlen(s);
		s[k/2]=0;
		sscanf(s,"%lld",&m);
		if(m<1+p10[k/2-1])
			ans=v[k-1].back()+n-(p10[k-1]-p10[k/2]);
		else
			ans=v[k][m]+n-m*p10[(k+1)/2];
		printf("Case #%d: %lld\n",++ts,ans);
	}
	return 0;
}