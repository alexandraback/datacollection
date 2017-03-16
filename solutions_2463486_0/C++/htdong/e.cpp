#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
#include<vector>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 40
#define MM 10010
int hw(int x)
{
	if(x<10) return 1;
	int a[NN]={0};
	while (x)
	{
		a[++a[0]]=x%10;
		x/=10;
	}
	for(int i=1;i<=a[0];i++)
		if(a[i]!=a[a[0]-i+1]) return 0;
	return 1;
}
int sq(int x)
{
	int a=max(0,(int)sqrt(x)-5);
	while (a*a<x) a++;
	if(a*a==x) return 1;
	return 0;
}
int main()
{
freopen("1.in","r",stdin);
freopen("1.out","w",stdout);
	int tt,_,a,b;
	scanf("%d",&_);
	for(tt=1;tt<=_;tt++)
	{
		scanf("%d%d",&a,&b);
		int ans=0;
		for(int i=a;i<=b;i++)
			if(sq(i))
			if(hw(i) && hw((int)sqrt(i))) ans++;
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
