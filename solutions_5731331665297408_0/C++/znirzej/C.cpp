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
int a,b,c,d,e,f,n,m,mx,l,z,r,k,x;
int wynik;
char ch;
int INF=1e9+1;
int t[9][9];
int pom[9][9];
int xx[9];
int wroc[9];
string cost[10];
bool moge()
{
for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
		{
		pom[i][j]=t[i][j];
		wroc[i]=0;
		}
	}
vector<int> V;
V.PB(xx[1]);
wroc[xx[1]]=1;
for(int i=2;i<=n;i++)
	{
//	printf("%d\n",xx[i]);
		{
		a=0;
		while(V.size())
			{
			if(t[V.back()][xx[i]]==1)
				{
				pom[V.back()][xx[i]]=0;
				pom[xx[i]][V.back()]=0;
				
				a=1;
				break;
				}
			V.pop_back();
			}
		wroc[xx[i]]=1;
		if(a==0)return 0;
		}
	V.PB(xx[i]);
	}
	
return 1;
}
string licz()
{
string ret="";
for(int i=1;i<=n;i++)ret=ret+cost[xx[i]];
return ret;
}
void solve()
{
for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
		{
		t[i][j]=0;
		}
	}

scanf("%d%d",&n,&m);
for(int i=1;i<=n;i++)
	{
	cin>>cost[i];
	}
for(int i=1;i<=m;i++)
	{
	scanf("%d%d",&a,&b);
	t[a][b]=1;
	t[b][a]=1;
	}

for(int i=1;i<=n;i++)xx[i]=i;
string wynik="a";
/*
xx[1]=5;
xx[2]=2;
xx[3]=3;
xx[4]=4;
xx[5]=1;
*/
do
	{
	if(moge())
		{
		wynik=min(wynik,licz());
		}
//		cout<<wynik<<endl;return;
	}
while(next_permutation(xx+1,xx+n+1));
cout<<wynik<<endl;
}
main()
{
scanf("%d",&z);
for(int ii=1;ii<=z;ii++)
	{
	printf("Case #%d: ",ii);	
	solve();
	}
}
