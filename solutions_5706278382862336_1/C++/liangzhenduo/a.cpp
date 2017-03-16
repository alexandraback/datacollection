#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
map<long long,int>d;
long long p,q;
long long gcd(long long a,long long b)
{
	if(a%b==0)return b;
	else return gcd(b,a%b);
}
int main()
{
	for(long long t=2,j=1;j<=40;j++,t*=2)
	{
		d[t]=j;
	}
	int T;
	scanf("%d",&T);
	for(int tcase=1;tcase<=T;tcase++)
	{
		scanf("%I64d/%I64d",&p,&q);
		long long t=gcd(p,q);
		p/=t;
		q/=t;
		if(d[q]==0)
		{
			printf("Case #%d: impossible\n",tcase);
			continue;
		}
		int ans=d[q]+1;
		t=1;
		while(p>=t)
		{
			ans--;
			t*=2;
		}
		printf("Case #%d: %d\n",tcase,ans);
	}
}
