/*
	Author : ChnLich
*/
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<bitset>
#include<functional>
#include<utility>

using namespace std;

typedef long long llint;
typedef pair<int,int> ipair;
typedef unsigned int uint;
#define pb push_back
#define fi first
#define se second
#define mp make_pair

const int MOD=1000000007,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
const double eps=1e-8;

void read(int &k)
{
	k=0; char x=getchar();
	while(x<'0'||x>'9') x=getchar();
	while(x>='0'&&x<='9') { k=k*10-48+x; x=getchar(); }
}

int R,n,m,K,v,o,c[20],tot[128],a[100];

void getnum(int x)
{
	memset(c,0,sizeof c);
	int len=0;
	for(;x;x/=(m-1))
		c[len++]=x%(m-1);
	for(int i=0;i<n;i++) c[i]+=2;
}

bool OK(int x)
{
	for(int i=0;i<v;i++) if (x==tot[i]) return 1;
	return 0;
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	
	puts("Case #1:");
	int T;
	scanf("%d",&T);
	scanf("%d%d%d%d",&R,&n,&m,&K);
	v=1<<n; o=1;
	for(int i=0;i<n;i++) o*=(m-1);
	for(int i,j;R--;)
	{
		for(i=0;i<K;i++) scanf("%d",a+i);
		for(i=0;i<o;i++)
		{
			getnum(i);
			memset(tot,0,sizeof tot);
			for(j=0;j<v;j++)
			{
				tot[j]=1;
				for(int k=0;k<n;k++) if ((j>>k)&1) tot[j]*=c[k];
			}
			for(j=0;j<K;j++) if (!OK(a[j])) break;
			if (j>=K)
			{
				for(int k=0;k<n;k++) printf("%d",c[k]);
				puts("");
				break;
			}
		}
	}
	
	return 0;
}
