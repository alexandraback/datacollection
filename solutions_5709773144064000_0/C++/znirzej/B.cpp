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
int a,b,d,e,n,m,mx,l,z,r,k;
int wynik;
char ch;
int INF=1e9+1;
LD c,f,x,spd,tim;
void solve()
{
scanf("%Lf%Lf%Lf",&c,&f,&x);
spd=2;
tim=0;
LD wynik=1e18;
while(1)
	{
	if(wynik<tim+x/spd){break;}
	wynik=min(wynik,tim+x/spd);
	tim=tim+c/spd;
	spd+=f;
	}
printf("%.7Lf\n",wynik);
}
main()
{
scanf("%d",&z);
for(int i=1;i<=z;i++)
	{
	printf("Case #%d: ",i);
	solve();
	}

}
