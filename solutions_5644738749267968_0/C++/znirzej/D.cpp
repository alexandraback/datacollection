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
int b,d,e,n,m,mx,l,z,r,k;
int wynik;
char ch;
int INF=1e9+1;
LD a;
vector <long double> x1,x2;
void solve()
{
x1.clear();
x2.clear();
scanf("%d",&n);
for(int i=1;i<=n;i++)
	{
	scanf("%Lf",&a);
	x1.PB(a);
	}
for(int i=1;i<=n;i++)
	{
	scanf("%Lf",&a);
	x2.PB(a);
	}
sort(ALL(x1));
sort(ALL(x2));
int wyn1=0,ww=0,wyn2=0;
int w=0;
for(int i=0;i<n;i++)
	{
	while(w<n&&x2[w]<x1[i])w++;
	if(w==n)
		{
		wyn2=n-i;
		break;
		}
	w++;
	}
for(int i=0;i<x1.size();i++)
	{
	while(x1.size()&&x1.back()>x2.back())
		{
		x1.pop_back();
		x2.pop_back();
		ww++;
		}
	
	if(x2.size()&&x2.back()>x1[i])x2.pop_back();
	else 
		{
		wyn1=x1.size()-i;
		break;
		}
	}
printf("%d %d\n",wyn1+ww,wyn2);
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
