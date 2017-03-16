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

int T,ts,n,c,i,ans;
long long m,a[500],t;

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&T);
	for(ts=1;ts<=T;ts++)
	{
		scanf("%d%d%lld",&c,&n,&m);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		sort(a,a+n);
		t=0;
		ans=0;
		for(i=0;i<n;i++)
			if(t+1>=a[i])
				t+=a[i]*c;
			else
			{
				ans++;
				t+=(t+1)*c;
				i--;
			}
		while(t<m)
		{
			ans++;
			t+=(t+1)*c;
		}
		printf("Case #%d: %d\n",ts,ans);
	}
	return 0;
}