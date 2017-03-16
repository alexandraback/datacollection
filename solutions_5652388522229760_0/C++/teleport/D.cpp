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
		int x;
		cin >> x;
		if (x == 0)
		{
			cout << "INSOMNIA\n";
			continue;
		}
		vector < int > digits(10);
		int y = x;
		while (true)
		{
			int z = y;
			while (z)
			{
				digits[z%10]++;
				z /= 10;
			}
			bool flag = true;
			for (int i = 0; i < 10; i++)
				if (digits[i] == 0)
					flag = false;
			if (flag)
			{
				cout << y << "\n";
				break;
			}
			y += x;
		}
	}
	
	return 0;
}
