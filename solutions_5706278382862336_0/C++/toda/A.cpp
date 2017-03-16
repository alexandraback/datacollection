#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>

#include <functional>
#include <limits>
#include <numeric>
#include <complex>

#include <cassert>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }

typedef long long LL;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ld, ld> ptd;
typedef unsigned long long uli;

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define ford(i, n) for(int i = int(n - 1); i >= 0; i--)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define pb push_back
#define mp make_pair
#define mset(a, val) memset(a, val, sizeof (a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ft first
#define sc second
#define sz(a) int((a).size())

const int INF = int(1e9);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);
using namespace std;
using namespace std;
 
long long int B[50];
 
long long int gcd(long long int a,long long int b)
{
	if(b==0)
	return a;
	else return gcd(b,a%b);
}
 
void preprocess()
{
	LL i = 1,j;
	B[0] = i; 
	for(j=1;j<=44;j++)
	{
		i *= 2;
		B[j] = i;
	}
}
int main()
{
	int t,i,j,cs;
	LL P,Q,W;
	freopen("inpA.in","r",stdin);
	freopen("outA.txt", "w", stdout);
    scanf("%d",&t);
	preprocess();
	for(cs=1;cs<=t;cs++)
	{
		scanf("%lld/%lld",&P,&Q);
		W = gcd(Q,P);
		P /= W;
		Q /= W;
 
		if(binary_search(B,B+41,Q))
		{
			j = 1;
			int ans = true;
			if(P>Q)
			{
				printf("Case #%d: impossible\n",cs);
				ans = false;
			}
			while(j<=40 && ans)
			{
				if(P>=Q/2)
				{
					printf("Case #%d: %d\n",cs,j);
					ans = false;
				}
				Q /= 2;
				j++;
			}
			if(ans)
			printf("Case #%d : impossible\n",cs);
		}
		else
		{
			printf("Case #%d: impossible\n",cs);
		}
	}
	return 0;
}
