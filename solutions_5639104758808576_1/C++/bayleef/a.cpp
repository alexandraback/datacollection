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

int T,n,ans,cur,i,ts;
char s[2000];

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&n,&s);
		ans=0;
		cur=s[0]-'0';
		for(i=1;i<=n;i++)
		{
			if(cur>=i)
				cur+=s[i]-'0';
			else
			{
				ans+=i-cur;
				cur=i+s[i]-'0';
			}
		}
		printf("Case #%d: %d\n",++ts,ans);
	}
	return 0;
}