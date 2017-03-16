#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <cmath>
#include <list>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <complex>
#include <assert.h>

using namespace std;

#define For(i,a,b,d) for (int i = (a); i != (b); i += d)
#define FORD(i,a,b) for (int i = (a); i >= b; i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REPD(i,n) for (int i = (n - 1); i >= 0; i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()
#define CLR(a,x) memset(a,x,sizeof(a))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define debug(x) cout << #x << "=" << x << endl;
#define Abs(a) (((a) < 0) ? (-(a)) : (a))
#define sqr(a) ((a)*(a))
#define pb push_back
#define mp make_pair
#define gc getchar_unlocked

typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int Inf = 1000000000;
const int M = 1000000000;
const ld eps = 10e-8;
const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

inline ll gcd (ll a, ll b){ return (!b ? a : gcd (b, a % b)); }

int rand15() { return rand() % (1 << 15); }
int rand30() { return (rand15() << 15) + rand15(); }
int rand(int L, int R) { if (L > R) return R; return rand30() % (R - L + 1) + L; }
ld random(ld L, ld R) { return rand(ceil((L-eps)*100), floor((R+eps)*100)) / 100.0;}

void scanint(int &x)
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
	if(neg) x=-x;
}

int main()
{
	int notc;
	scanf("%d", &notc);
	FOR(tc, 1, notc)
	{
		long long int a, b, k, total=0;
		scanf("%lld %lld %lld", &a, &b, &k);
		REP(i, a)
		{
			REP(j, b)
			{
				if ((i&j)<k)	{++total; }//cout<<i<<"  "<<j<<endl;}
			}
		}
		
		/*ll min1=a<b?a:b;
		ll max1=min1==a?b:a;
		
		ll total=0;
		if (min1<k)	{ total=a*b;	}
		else
		{
			total+=max1*k + k;
			
			for(ll i=k+1;i<min1; ++i)
			{
				total+=
			}	
		}*/
		
		
		printf("Case #%d: %lld\n", tc, total);			
	}	
	return 0;
}
