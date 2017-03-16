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
		cout << "Case #" << t << ":\n";
		int n, j;
		cin >> n >> j;
		vector < pair < vector < int >, vector < int > >  > ans;
		for (int msk = 0; msk < (1 << (n - 2)); msk++)
		{
			vector < int > bits;
			bits.pb(1);
			for (int i = 0; i < n - 2; i++)
				if (msk & (1 << i))
					bits.pb(1);
				else
					bits.pb(0);
			bits.pb(1);
			vector < int > dels;
			bool globflag = true;
			for (int st = 2; st <= 10; st++)
			{
				bool flag = false;
				for (int p = 2; p <= 11; p++)
				{
					int ost = 0;
					for (auto x : bits)
						ost = (ost * st + x) % p;
					if (ost == 0)
					{
						flag = true;
						dels.pb(p);
						break;
					}
				}
				if (!flag)
					globflag = false;
			}
			if (!globflag)
				continue;
			ans.pb(mp(bits, dels));	
			if ((int)ans.size() == j)
				break;
		}
		for (auto x : ans)
		{
			for (auto y : x.fst)
				cout << y;
			for (auto y : x.snd)
				cout << " " << y;
			cout << "\n";
		}
	}
	
	return 0;
}
