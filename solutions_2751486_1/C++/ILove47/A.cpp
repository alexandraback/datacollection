//#pragma comment(linker, "/stack:16777216")
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
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

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define FILL(a,v) memset(a,v,sizeof(a))

const double PI = acos(-1.0);
const double EPS = 1e-7;

typedef long long ll;
typedef unsigned long long ull;

string s;
ll l;
ll a[1000747];
ll b[1000747];
ll c[1000747];
ll d[1000747];

ll f(ll l, ll r)
{
	ll w = c[l];
	ll len = r;
	while (r-l > 0)
	{
		ll m = (r+l)>>1;
		if (d[m] > w)
			r = m;
		else
			 l = m+1;
	}
	if (d[l] > w)
		return len - l;
	return 0;
}

void solve()
{
	FILL(a,0);
	FILL(b,0);
	FILL(c,0);
	FILL(d,0);
	cin >> s >> l;
	if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u')
		a[0] = 0;
	else
		a[0] = 1;
	int length = s.length();
	for (int i = 0; i != length; ++i )
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			a[i] = 0;
		else
			a[i] = a[i-1] + 1;
	for (int i = 0; i != length; ++i)
		if (a[i] >= l)
			b[i] = 1;

	c[0] = 0;
	for (int i = 1; i != length ; ++i)
		c[i] = c[i-1] + b[i+l-2];


	d[0] = b[0];
	for (int i = 1; i != length; ++i)
		d[i] = d[i-1] + b[i];

	ll res = 0;

	for (int i = 0; i != length; ++i)
		res += f(i, length);
	cout << res << endl;

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int tests;
	scanf("%d", &tests);
	++tests;
	for (int i = 1; i != tests; ++i)
	{
		printf("Case #%d: ", i);
		int time = clock();
		solve();
		cerr<<"Case #"<<i<<"\t time="<<clock()-time<<endl;
	}
}