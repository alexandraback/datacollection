#include <ctime>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
using namespace std;


#define PB	push_back
#define MP  make_pair
#define ALL(a) 	(a).begin(), (a).end()
#define FILL(a,v) memset(a,v,sizeof(a))

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ABS(A) ((A) < 0 ? (-(A)) : (A))
#define SQR(x) (x)*(x)

const double PI = acos(-1.0);
const double EPS = 1e-7;

const int INF = 2000000000;

typedef long long ll;

ll gcd(ll a, ll b)
{
	return a?gcd(b%a,a):b;
}

void solve()
{
	ll TwoIn40 = 1<<20;
	TwoIn40*=TwoIn40;

	ll p,q;
	char c;
	cin >> p >> c >> q;
	ll g = gcd(p,q);
	p/=g;
	q/=g;

	if (TwoIn40%q != 0)
	{
		cout << "impossible";
		return;
	}

	int cnt = 0;
	bool b = true;
	int kk=0;
	while(true)
	{
		g = gcd(p,q);
		p/=g;
		q/=g;
		if (b)
		{
			++cnt;
		}
		++kk;
		q/=2;
		if (p>=q)
		{
			p-=q;
			cout << cnt;
			return;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test)
	{
		cout << "Case #"<<test<<": ";
		solve();
		cout << endl;
	}
	return 0;
} 
/*

13/16
8/8			5/8
4/4			1/4
1/2		0/1
1/1		0






3/8
0 3/4
1 1/2
0 1

3/8
1/4 2/4
0 1/2 0 1
0 1

*/