#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <fstream>

using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double

template<typename T>
T abs(T x) {
	return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
	return x * x;
}

template<typename T>
ostream& operator << (ostream &s, const vector<T> &x) {
	s << "[";
	for (auto it : x) {
		s << it << ", ";
	}
	s << "]";
	return s;
}

template<typename T>
ostream& operator << (ostream &s, const set<T> &x) {
	s << "{";
	for (auto it : x) {
		s << it << ", ";
	}
	s << "}";
	return s;
}


template<typename U, typename V>
ostream operator << (ostream &s, const pair<U, V> &x) {
	cout << "(" << x.fst << ", " << x.snd << ")";
	return s;
}

template<typename T>
bool chmax(T &x, const T &y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

template<typename T>
bool chmin(T &x, const T &y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}

//---------------------------------------------------------------------

int main() {
	
	#ifdef LOCAL
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
	#else
	#endif
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		ll k, c, s;
		cin >> k >> c >> s;
		if ((k - 1) / c + 1 > s)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		for (int i = 0; i < k; i += c)
		{
			ll x = 0;
			for (int j = 0; j < c; j++)
				x = x * k + min(k - 1, (ll)i + j);
			cout << x + 1 << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
