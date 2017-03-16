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
ostream& operator << (ostream &s, const pair<U, V> &x) {
	s << "(" << x.fst << ", " << x.snd << ")";
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

map < string , string > mt;
map < string, bool > used;
map < string, vector < string > > g;


bool try_kuhn(string v)
{
	if (used.count(v) != 0)
		return false;
	used[v] = true;
	
	for (auto to : g[v])
	{
		if (mt.count(to) == 0 || try_kuhn(mt[to]))
		{
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main() {
	
	#ifdef LOCAL
		//gen();
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
	#else
		//freopen("springs.in", "r", stdin);
		//freopen("springs.out", "w", stdout);
	#endif
	
	int T;
	cin >> T;
	for (int iter = 1; iter <= T; iter++)
	{
		cout << "Case #" << iter << ": ";
		int n;
		cin >> n;
		set < string > fir, sec;
		mt.clear(); used.clear(), g.clear();
		for (int i = 0; i < n; i++)
		{
			string s, t;
			cin >> s >> t;
			g[s].pb(t);
			fir.insert(s); sec.insert(t);
		}
		
		int ans = (int)fir.size() + (int)sec.size();
		
		for (auto x : fir)
		{
			used.clear();
			try_kuhn(x);
		}
		
		int dual = 0;
		for (auto x : sec)
		{
			if (mt.count(x) != 0)
			{
				dual++;
			}
		}
		
		ans -= dual;
		cout << n - ans << "\n";
	}
	return 0;
}
