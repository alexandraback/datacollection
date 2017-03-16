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
typedef pair<int,int> PII;
const int oo=1047483647,maxn=10001000;
LL n,i,j,k,m,q,aa,b,ans[maxn+10],a[10000],r;
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
bool ok(LL X)
{
	LL l=0;
	while (X)
	{
		a[++l]=X%10;
		X/=10;
	}
	LL i;
	fo(i,1,l/2)
	if (a[i]!=a[l-i+1]) return 0;
	return 1;
}
LL ask(LL RT)
{
	LL an=0,i;
	fo(i,1,r)
	if ((LL)ans[i]*ans[i]<=RT) an++;
	else break;
	return an;
}
int main()
{
//	freopen("3.in","r",stdin);
 //freopen("3.out","w",stdout);
	LL z;
	LL	T=Read();
	fo(i,1,maxn)
	{
		LL u=(LL)i*i;
		if (ok(i) && ok(u))
		ans[++r]=i;
	}
	fo(z,1,T)
	{
		aa=Read();b=Read();
		int An=ask(b)-ask(aa-1);
        printf("Case #%d: ",z);
        cout<<An<<endl;
	}
	return 0;
}
