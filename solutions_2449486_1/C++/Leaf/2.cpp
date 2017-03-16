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
const int oo=1047483647,maxn=110;
int n,i,j,k,m,q,T;
int a[maxn][maxn],r[maxn],t[maxn];
bool kind;
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
//	freopen("2.in","r",stdin);
  //freopen("2.out","w",stdout);
	int z;
	T=Read();
	fo(z,1,T)
	{
		n=Read();m=Read();
        memset(r,0,sizeof r);
		memset(t,0,sizeof t);
		fo(i,1,n)
		fo(j,1,m)
		{
			a[i][j]=Read();
			r[i]=max(r[i],a[i][j]);
			t[j]=max(t[j],a[i][j]);
		}
		kind=1;
		fo(i,1,n)
		{
		fo(j,1,m)
		{
			if (r[i]>a[i][j] && t[j]>a[i][j])
			{
				kind=0;break;
			}
		/*	fo(k,1,n)
			if (a[k][j]<a[i][j])
			{
				kind=0;
				break;
			}
			if (kind) continue;
			fo(k,1,m)
			if (a[i][k]<a[i][j])
			{
				kind=0;
				break;
			}
			if (!kind)
			{
				break;
			}*/
		}
		if(!kind) break;
		}
		printf("Case #%d: ",z);
		if (kind) puts("YES");
		else puts("NO");
	}
	return 0;
}
