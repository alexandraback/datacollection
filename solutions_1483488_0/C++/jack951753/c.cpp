#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int A,B;
int calc(int a)
{
//	printf("%d:\n",a);
	set<int> s;
	int m=1;
	for(int i=a;i>9;i/=10,m*=10);
	int b=a,c=a;
	for(;b>0;b/=10)
	{
		c=c/10+(c%10)*m;
//		printf("%d ",c);
		if(c>a&&c>=A&&c<=B)
			s.insert(c);
	}
//	printf("\n\n");
	return s.size();
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;scanf("%d",&T);

	for(int i=1;i<=T;i++)
	{
		int ans=0;
		printf("Case #%d: ",i);
		scanf("%d%d",&A,&B);
		for(int j=A;j<=B;j++)
			ans+=calc(j);
		printf("%d\n",ans);
	}	
}