#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <iterator>
#include <cstdio>
#include <list>

using namespace std;

#define rs resize
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back
#define ms(a) memset(a, 0, sizeof(a))
#define ass assign
#define inf (int)1e9
#define pi 3.1415926535
#define reverse(a) reverse((a).begin(),(a).end())
#define sort(a) sort((a).begin(),(a).end())
#define sf scanf
#define pf printf

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <ll> vl;
typedef vector <vl> vvl;
typedef vector <vvl> vvvl;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef set <int> si;
typedef queue <int> qi;
typedef vector <string> vs;
typedef vector <bool> vb;
typedef unsigned long long ull;
typedef vector <vb> vvb;

ll gcd(ll a, ll b)
{
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

ll get_ans(ll p, ll q)
{
	if (p * 2 >= q)
		return 1;
	else
		return get_ans(2 * p, q) + 1;
}

void solve()
{
	ll p, q;
	sf("%lld/%lld", &p, &q);
	ll d = gcd(p, q);
	p /= d, q /= d;
	ll q1 = q;
	while (q1 % 2 == 0)
		q1 /= 2;
	if (q1 != 1)
	{
		cout << "impossible\n";
		return ;
	}
	cout << get_ans(p, q) << endl;
	return ;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
}