#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int		n,sum,res;
char	s[1010];

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	int test,tid=0;

	for (scanf("%d",&test);test--;)
	{		
		scanf("%d%s",&n,s);
		printf("Case #%d: ",++tid);
		sum=res=0;
		for (int i=0;i<=n;i++)
		{
			sum+=s[i]-'0';
			if (sum<i+1)
				res+=i+1-sum,sum=i+1;
		}
		printf("%d\n",res);
	}
}