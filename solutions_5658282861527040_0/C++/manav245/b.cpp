#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{

int T;
freopen("i1.txt","r",stdin);
freopen("o1.txt","w",stdout);
scanf("%d",&T);
char s[100][200];
long long i,h,j,k;
long long a,b,c;
for(int t=0;t<T;t++)
	{
	scanf("%lld %lld %lld",&a,&b,&c);
	h=0;
	for(i=0;i<a;i++)
		{
		for(j=0;j<b;j++)
			if((i&j)<c)
				h++;
		}
	printf("Case #%d: %lld\n",t+1,h);	
	}
return 0;
}
