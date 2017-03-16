#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	freopen("C:\\fdsfsda\\A-large (9).in","r",stdin);
	freopen("C:\\fdsfsda\\Aout.txt","w",stdout);
	int s,n,i,j,k,a[111],cas,cc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d",&s,&n);
		for (i=0;i<n;i++)scanf("%d",a+i);
		if (s==1)
		{
			printf("Case #%d: %d\n",++cc,n);
			continue;
		}
		sort(a,a+n);
		int ans=n,t=0;
		for (i=0;i<n;)
		{
			//printf("%d %d\n",i,s);
			if (a[i]<s)
			{
				s+=a[i];
				ans=min(ans,t+n-i-1);
				i++;
			}
			else 
			{
				ans=min(ans,t+n-i);
				s+=s-1;
				t++;
			}
		}
		printf("Case #%d: %d\n",++cc,ans);
	}
	return 0;
}

