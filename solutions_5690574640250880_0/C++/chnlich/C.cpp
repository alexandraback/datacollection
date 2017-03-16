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

int T,n,m,B;

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		printf("Case #%d:\n",tt);
		scanf("%d%d%d",&n,&m,&B);
		B=n*m-B;
		if (n==1||m==1)
		{
			for(int i=0;i<n;i++,puts(""))
				for(int j=0;j<m;j++)
					if (B!=n*m)
						printf("*"),B++;
					else if (i==n-1&&j==m-1)
						printf("c");
					else
						printf(".");
			continue;
		}
		if (B==1)
		{
			for(int i=0;i<n;i++,puts(""))
				for(int j=0;j<m;j++)
					if (i==0&&j==0)
						printf("c");
					else
						printf("*");
			continue;
		}
		int x,y;
		for(x=2;x<=n;x++)
		{
			for(y=2;y<=m;y++) if (x*2+y*2-4<=B&&x*y>=B) break;
			if (y<=m) break;
		}
		if (x>n)
		{
			puts("Impossible");
			continue;
		}
		B-=x*2+y*2-4;
		for(int i=0;i<n;i++,puts(""))
			for(int j=0;j<m;j++)
				if (i==0&&j==0) printf("c");
				else if ((i<x&&j<2)||(i<2&&j<y)) printf(".");
				else if (i<x&&j<y&&B) printf("."),B--;
				else printf("*");
	}
	
	return 0;
}
