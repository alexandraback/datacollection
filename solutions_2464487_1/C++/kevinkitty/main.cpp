#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

typedef __int64 Uint;
const int MAX=500005;
const int N=1005;
bool f(Uint r,Uint n,Uint t)
{

	Uint zheng,yu;
	zheng = t/n;
	yu=t%n;
	Uint tp;
	zheng=(zheng+1)>>1;
	return (n>zheng || r>zheng || (n+r)>zheng);
}
Uint erfen(Uint low,Uint high,Uint r,Uint t)
{
	Uint mid;
	while(true)
	{
		mid=(low+high)>>1;
		if(f(r,mid,t))high=mid;
		//	if(tmp>t)high=mid;
		else low=mid;
		if(low==high || high==low+1)return (low+high)>>1;
	}
}
int main()
{
	int T,cse=0;
	Uint r,t;
		freopen("data.in","r",stdin);
		freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%I64d",&r,&t);
		Uint ret=erfen(0,t,r,t);
		printf("Case #%d: ",++cse);
		printf("%I64d\n",ret);
	}
	return 0;
}
/*

5
1 9
1 10
3 40
1 1000000000000000000
10000000000000000 1000000000000000000
*/