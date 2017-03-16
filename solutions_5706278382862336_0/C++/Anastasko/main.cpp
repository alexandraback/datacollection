//#pragma comment(linker, "/STACK:134217728")
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define INF 1000000007
#define y1 agaga
#define ll long long
#define ull unsigned long long


int t;
ll a, b;

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> t;

	FOR(T,1,t+1)
	{
		scanf("%lld/%lld", &a, &b);
		ll g = gcd(a, b);
		a /= g; b /= g;

		ll sol=0;
		bool ok = false;

			while (a < b)
			{
				a *= 2;
				sol++;

				ll g = gcd(a, b);
				a /= g; b /= g;
			}

			int iter = 1000;

			while (a != b && iter--)
			{
				a -= b;

				while (a < b)
				{
					a *= 2;

					ll g = gcd(a, b);
					a /= g; b /= g;
				}
			}

			ok = iter>0;			
		

		if (ok)
			cout << "Case #" << T << ": " << sol << endl;
		else
			cout << "Case #" << T << ": impossible"<< endl;
	}

	return 0;
}