#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

char s[50000];
char pref[50000];
char suf[50000];
int T,ts;
int sgn;
char c;
int n,i,j;
long long k;

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld%s",&n,&k,&s);
		for(i=0;i<3*n;i++)
			s[n+i]=s[i];
		sgn=1;
		c='1';
		for(i=0;i<4*n;i++)
		{
			if(c=='1')
				c=s[i];
			else if(c==s[i])
			{
				c='1';
				sgn=-sgn;
			}
			else 
			{
				if((s[i]-c+3)%3==2)
					sgn=-sgn;
				c='i'+'j'+'k'-c-s[i];
			}
			pref[i]=c*sgn;
		}
		sgn=1;
		c='1';
		for(i=4*n-1;i>=0;i--)
		{
			if(c=='1')
				c=s[i];
			else if(c==s[i])
			{
				c='1';
				sgn=-sgn;
			}
			else
			{
				if((c-s[i]+3)%3==2)
					sgn=-sgn;
				c='i'+'j'+'k'-c-s[i];
			}
			suf[i]=c*sgn;
		}
		if(k%4==0)
		{
			printf("Case #%d: NO\n",++ts);
			continue;
		}
		if(k%2 && pref[n-1]!=-'1')
		{
			printf("Case #%d: NO\n",++ts);
			continue;
		}
		if(k%4==2 && (pref[n-1]=='1' || pref[n-1] == -'1'))
		{
			printf("Case #%d: NO\n",++ts);
			continue;
		}
		for(i=0;i<4*n;i++)
			if(pref[i]=='i')
				break;
		if(i==4*n)
		{
			printf("Case #%d: NO\n",++ts);
			continue;
		}
		for(j=4*n-1;j>=0;j--)
			if(suf[j]=='k')
				break;
		if(j==-1)
		{
			printf("Case #%d: NO\n",++ts);
			continue;
		}
		if(i>=n*(k-4)+j)
		{
			printf("Case #%d: NO\n",++ts);
			continue;
		}
		printf("Case #%d: YES\n",++ts);
	}
	return 0;
}
