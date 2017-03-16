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
const int oo=1047483647,maxn=310;
LL n,i,j,k,m,q,E,R,T;
LL f[100][10];
int Read()
{
	char ch;while (ch = getchar(), (ch < '0' || ch > '9') && (ch != '-')); 
	bool neg= (ch == '-');
	if (ch=='-') ch=getchar();
	int v=0;
	while (ch>='0' && ch<='9') v=v*10+ch-'0',ch=getchar();
	if (neg) v=-v;
	return v;
}
int main()
{
	freopen("2.in","r",stdin);
  freopen("2.out","w",stdout);
	T=Read();
	int ca;
	fo(ca,1,T)
	{
		E=Read();R=Read();n=Read();
		memset(f,0,sizeof f);
		fo(i,0,n-1)
		{
			LL v=Read();
			fo(j,0,E)
			{
				LL t=j+R;
				if (t>E) t=E;
				fo(k,0,t)
				f[i+1][t-k]=max(f[i+1][t-k],f[i][j]+k*v);
			}
		}
		LL ans=0;
		fo(i,0,E)
		ans=max(ans,f[n][i]);
        printf("Case #%d: %I64d\n",ca,ans);
	}
	return 0;
}
