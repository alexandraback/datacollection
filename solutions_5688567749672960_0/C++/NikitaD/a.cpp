#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;

template <class T> inline T sqr(const T& a) { return a * a; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

unordered_map<ll, ll> cnt;

ll inline rev(ll n)
{
	ll res = 0;
	while (n)
	{
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}


ll getAns(ll n)
{
	//cout << n << " - ";

	if (n == 1)
		return 1;

	if (cnt.count(n))
		return cnt[n];

	//if (n == 23)
	//	cout << "here\n";

	ll &ans = cnt[n] = n;
	updMin(ans, getAns(n - 1) + 1);

	if (n % 10)
	{
		ll r = rev(n);
		if (r < n)
			updMin(ans, getAns(r) + 1);
	}

	return ans;
}


void solution()
{
	ll n;
	cin >> n;
	ll ans = getAns(n);
	cout << ans;
}



int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);


	int nTests;
	cin >> nTests;
	for (int test = 1; test <= nTests; ++test)
	{
		cout << "Case #" << test << ": ";
		solution();
		cout << "\n";
	}



	return 0;
}
