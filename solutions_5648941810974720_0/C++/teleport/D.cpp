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

string numbers[] = {"ZERO", "TWO", "FOUR", "FIVE", "SIX", "SEVEN", "ONE", "THREE", "EIGHT", "NINE"};
int order[] = {0, 2, 4, 5, 6, 7, 1, 3, 8, 9};

int cnt[26];

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
		string s;
		cin >> s;
		cout << "Case #" << iter << ": ";
		for (int i = 0; i < (int)s.length(); i++)
		{
			cnt[s[i]-'A']++;
		}
		vector < int > ans;
		while (true)
		{
			//cout << ans << "\n";
			bool flag1 = false;
			for (int i = 0; i < 26; i++)
				if (cnt[i] > 0)
					flag1 = true;
			if (!flag1)
				break;
			for (int i = 0; i < 10; i++)
			{
				bool flag = true;
				for (int j = 0; j < (int)numbers[i].length(); j++)
				{
					if (cnt[numbers[i][j]-'A'] == 0)
					{
						for (int k = 0; k < j; k++)
							cnt[numbers[i][k]-'A']++;
						flag = false;
						break;
					}
					cnt[numbers[i][j]-'A']--;
				}
				if (flag)
				{
					ans.pb(order[i]);
					break;
				}
			}
		}
		sort(ans.begin(), ans.end());
		for (auto x : ans)
			cout << x;
		cout << "\n";
	}
	
	return 0;
}
