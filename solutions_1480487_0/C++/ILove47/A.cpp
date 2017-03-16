#pragma comment(linker,  "/STACK:16777216")
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <locale>
#include <climits>

using namespace std;

typedef long long ll;
typedef unsigned long long Ull;

#define VI vector <int>
#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b) for(int (i) = (a)-1; (i) >= (b); --(i))
#define CLEAR(a) memset((a), , sizeof(a))
#define INF 1000000000
#define PB push_back
#define ALL(c) (c).begin(),  (c).end()
#define pi 2*acos(0.0)
#define SQR(a) (a)*(a)
#define MP make_pair
#define MOD 1000000007
#define EPS 1e-7
#define INF 2000000000

ll T,TT,n,k,l,r,p,res,S;
ll a[447];
double Res[447];

ll F(ll x, ll pos)
{
	ll r = 0;
	FOR(i,0,n)
		if (i!=pos && a[i]<x)
			r += x-a[i];
	return r;
}

int main()
{
	freopen("inputA.txt","r",stdin);
	freopen("outputA.txt","w",stdout);

	cin >> TT;
	FOR(T,0,TT)
	{
		cin >> n;
		S = 0;
		FOR(i,0,n)
		{
			cin >> a[i];
			a[i] *= 10000000000000;
			S += a[i];
		}
		
		FOR(i,0,n)
		{
			res = 0;
			l = a[i];
			r = a[i] + S+1;

			while (r>l)
			{
				p = (l+r+1) >> 1;
				k = F(p,i);
				if (k <= S - p + a[i])
					l = p;
				else r = p-1;
			}
			res = l - a[i];
			Res[i] = (double)res/S;
		}
		printf("Case #%d:",T+1);
		FOR(i,0,n)
			printf(" %.9f",Res[i]*100);
		printf("\n");
	}
	return 0;
}