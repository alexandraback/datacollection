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
int n,i,j,k,m,q,r,T,K;
int a[10],b[10];
bool flag[200];
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
void dfs(int dep,int S)
{
	if (dep>3)
	{
		flag[S]=1;
		return;
	}
	dfs(dep+1,S);
	dfs(dep+1,S*b[dep]);
}
int main()
{
	freopen("3.in","r",stdin);
 freopen("3.out","w",stdout);
	T=Read();
	printf("Case #1:\n");
	r=Read();n=Read();m=Read();K=Read();
	while (r)
	{
		fo(i,1,K)
		{
			a[i]=Read();
			flag[a[i]]=1;
		}
		bool er=0;
	/*	if (r<45)
		{
			printf("111\n");
			r--;continue;
		}
		*/fo(i,2,m)
		{
		fo(j,2,m)
		{
		fo(k,2,m)
		{
            memset(flag,0,sizeof flag);
			b[1]=i;b[2]=j;b[3]=k;
			dfs(1,1);
			int r,cnt=0;
			fo(r,1,K)
			if (a[r]<=m*m*m && flag[a[r]]) cnt++;
			if (cnt==K)
			{
				er=1;break;
			}
		}
		if (er) break;
		}
		if (er) break;
		}
		printf("%d%d%d\n",b[1],b[2],b[3]);
		r--;
	}
	return 0;
}
