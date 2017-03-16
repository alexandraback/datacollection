#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<functional>
#include<iostream>
#include<map>
#include<bitset>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define MP(a,b) make_pair(a,b)
#define clr(x,y) memset(x,y,sizeof x)
#define fi first
#define se second
#define LL long long
#define sqr(z) ((z)*(z))
using namespace std;
typedef pair<LL,LL> PII;
const int oo=1047483647,maxn=1110;
LL n,i,j,k,m,q,T,R,t,ans;
LL Read()
{
	char ch;while (ch = getchar(), (ch < '0' || ch > '9') && (ch != '-')); 
	bool neg= (ch == '-');
	if (ch=='-') ch=getchar();
	LL v=0;
	while (ch>='0' && ch<='9') v=v*10+ch-'0',ch=getchar();
	if (neg) v=-v;
	return v;
}
bool check(LL n)
{
	LL RT=t-(2*n*n-n);
	return R<=RT/(2*n);
}
int main()
{
	freopen("Bullseye.in","r",stdin);
  freopen("Bullseye.out","w",stdout);
	T=Read();
	int ca=0;
	for (;T;T--)
	{
		ca++;
		R=Read();t=Read();
		ans=0;
		LL l=0,r=707106780LL;
		check(50);
		while (l<r)
		{
			LL mid=(l+r+1)/2;
			if (check(mid)) l=mid;
			else r=mid-1;
		}
		printf("Case #%d: %I64d\n",ca,l);
	}
	return 0;
}
