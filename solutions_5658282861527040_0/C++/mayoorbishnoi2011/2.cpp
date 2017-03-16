/*Mayoor Bishnoi*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<stack>

#define inp(n) scanf("%d",&n);
#define inp2(x,y) scanf("%d%d",&x,&y);
#define inpl(n) scanf("%lld",&n);
#define inpl2(x,y) scanf("%lld%lld",&x,&y);
#define out(n) printf("%d\n",n);
#define outl(n) printf("%lld\n",n);
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,b,a) for(int i=b-1;i>=a;i--)
#define PB(a) push_back(a)
#define C(x) printf("%d\n",x);
#define MAX 1000010

using namespace std;

typedef vector< int > vi;
typedef pair< int,int > pii;
typedef vector< pii > vpii;
typedef list< int > li;
typedef long long ll;
typedef unsigned long long ull;

/*int gcd(int a,int b)
{
	while(b)
		b^=a^=b^=a%=b;
	return a;
}*/

/*int mypower(int base,int index)
{
	if(index == 0)
		return 1;
	else if(index == 1)
		return base;
	int temp=mypower(base,index/2);
	temp=(temp*temp);
	if(index&1)
		return temp*base;
	else
		return temp;
}*/

main()
{
	int t,a,b,k,num=1;
	inp(t)
	while(t--)
	{
		inp(a)
		inp(b)
		inp(k)
		int ans=0;
		FOR(i,0,a)
			FOR(j,0,b)
			{
				if( (i&j) < k)
					ans++;
			}
		printf("Case #%d: %d\n",num,ans);
		num++;
	}
	return 0;
}