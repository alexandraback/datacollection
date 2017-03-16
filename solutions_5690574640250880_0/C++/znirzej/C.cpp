#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<tr1/unordered_map>
#include<queue>
#include<cstdlib>
#include<list>
#include<set>
#include<map>
#define MP make_pair
#define PB push_back
#define s second
#define f first
#define PII pair<int,int>
#define VPII vector <pair<int,int> >
#define VI vector <int>
#define abs(a) max((a),-(a))
#define LL long long
#define LD long double
#define ALL(x) x.begin(),x.end()
#define PU putchar_unlocked
#define GU getchar_unlocked
#define DBG(x) cerr<<#x<<" "<<(x)<<endl;
using namespace std;
int a,b,d,x,e,n,m,mx,l,z,r,k;
int wynik;
char ch;
int INF=1e9+1;
VI v;
int t[52][52];
int il[52][52];
int odw[52][52];
#define obok(i,j) (t[i-1][j-1]+t[i-1][j]+t[i-1][j+1]+t[i][j-1]+t[i][j]+t[i][j+1]+t[i+1][j-1]+t[i+1][j]+t[i+1][j+1])
#define zero(i,j) (il[i-1][j-1]*il[i-1][j]*il[i-1][j+1]*il[i][j-1]*il[i][j]*il[i][j+1]*il[i+1][j-1]*il[i+1][j]*il[i+1][j+1])
void dfs(int a,int b)
{
//cout<<a<<" a "<<b<<endl;
if(a==0||b==0||a>n||b>m||odw[a][b])return;

odw[a][b]=1;

if(obok(a,b))return;
dfs(a-1,b-1);
dfs(a-1,b);
dfs(a-1,b+1);
dfs(a,b-1);
dfs(a,b+1);
dfs(a+1,b-1);
dfs(a+1,b);
dfs(a+1,b+1);
}
bool aaa()
{
for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=m;j++)
		{
		if(t[i][j]==0&&odw[i][j]==0){//cout<<i<<" "<<j<<endl;
		return 0;}
		}
	}
return 1;
}
bool spr()
{
for(int i=1;i<=n+1;i++)
	{
	for(int j=1;j<=m+1;j++)
		{
		t[i][j]=0;
		il[i][j]=1;
		odw[i][j]=0;
		}
	}

int w=0;
for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=m;j++)
		{
		t[i][j]=v[w];
		w++;
		}
	}
int y=1;
for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=m;j++)
		{
		if(y&&obok(i,j)==0)
			{
			dfs(i,j);
			if(aaa()==0)return 0;
			y=0;
			}
		
		}
	}
if(y==1)return 0;

a=0;
for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=m;j++)
		{
		if(a==0&&obok(i,j)==0)
			{
			a=1;
			printf("c");
			continue;
			}
		printf("%c",t[i][j]==0?'.':'*');
		}
	puts("");
	}
return 1;
}
void solve()
{
v.clear();
scanf("%d%d%d",&n,&m,&x);

if(n*m==x+1)
	{
	for(int i=1;i<=n;i++)
		{
		for(int j=1;j<=m;j++)
			{
			if(i==1&&j==1)printf("c");
			else printf("*");
			}
		puts("");
		}
	return;
	}

for(int i=1;i<=n*m-x;i++)
	{
	v.PB(0);
	}
for(int i=1;i<=x;i++)
	{
	v.PB(1);
	}
b=0;
do
	{
	if(spr()){b=1;break;}//return;
	}
while(next_permutation(ALL(v)));

if(b==0){//printf("%d %d %d ",n,m,x);
puts("Impossible");}
}
main()
{/*
n=3;
m=3;
x=5;
v.PB(0);v.PB(0);v.PB(1);
v.PB(0);v.PB(0);v.PB(1);
v.PB(1);v.PB(1);v.PB(1);
cout<<spr();
*/
for(int i=0;i<=51;i++)for(int j=0;j<=51;j++)il[i][j]=1;

scanf("%d",&z);
for(int i=1;i<=z;i++)
	{
	printf("Case #%d:\n",i);
	solve();
	}

}
