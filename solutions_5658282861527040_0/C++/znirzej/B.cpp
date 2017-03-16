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
vector <PII> t[103];
string s;
void solve()
{
wynik=0;
scanf("%d%d%d",&a,&b,&k);
for(int i=0;i<a;i++)
	{
	for(int j=0;j<b;j++)
		{
		if((i&j)<k)wynik++;
		}
	}
printf("%d\n",wynik);
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
