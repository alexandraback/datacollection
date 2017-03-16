#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const int N = 100100;

ll gcd(ll a, ll b)
{
	return b? gcd(b, a%b): a;
}

void get_ans()
{
	ll a, b;
	char c;
	cin >> a >> c >> b;
	ll d = gcd(a,b);
	a /= d;
	b /= d;

	ll res = 0;
	d = b;
	while(b%2 == 0) {
		b /= 2;
		++res;
	}
	if (b != 1) {
		cout << "impossible\n";
	} else {
		res = 0;
		b = d;
		while(a < b)
		{
			b /= 2;
			++res;
		}
		cout << res << endl;
	}
}


int main()
{
	int cas, tcas = 0;
	for (cin >> cas; cas; --cas)
	{
		printf("Case #%d: ", ++tcas);
		get_ans();
	}
}
