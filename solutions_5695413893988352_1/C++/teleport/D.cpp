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

ll getint(string s)
{
	ll ans = 0;
	for (int i = 0; i < (int)s.length(); i++)
		ans = ans * 10 + (s[i] - '0');
	return ans;
}

string sfill(string s, char t)
{
	for (int i = 0; i < (int)s.length(); i++)
		if (s[i] == '?')
			s[i] = t;
	return s;
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
		
		string s, t;
		cin >> s >> t;
		int n = (int)s.length();
		string anss = s, anst = t;
		ll mini = 2e18;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != '?' && t[i] != '?')
			{
				if (s[i] != t[i])
				{
					for (int g = 0; g < 10; g += 9)
					{
						string ss = sfill(s, (char)('0' + g)), tt = sfill(t, (char)('0' + 9-g));
						if (abs(getint(ss) - getint(tt)) < mini || (abs(getint(ss) - getint(tt)) == mini && mp(anss, anst) > mp(ss, tt)))
						{
							mini = abs(getint(ss) - getint(tt));
							anss = ss;
							anst = tt;
						}
					}
					break;
				}
				continue;
			}
			else if (s[i] == '?' && t[i] == '?')
			{
				s[i] = '0'; t[i] = '1';
				string ss = sfill(s, '9'), tt = sfill(t, '0');
				if (abs(getint(ss) - getint(tt)) < mini || (abs(getint(ss) - getint(tt)) == mini && mp(anss, anst) > mp(ss, tt)))
				{
					mini = abs(getint(ss) - getint(tt));
					anss = ss;
					anst = tt;
				}
				
				s[i] = '1'; t[i] = '0';
				ss = sfill(s, '0'), tt = sfill(t, '9');
				if (abs(getint(ss) - getint(tt)) < mini || (abs(getint(ss) - getint(tt)) == mini && mp(anss, anst) > mp(ss, tt)))
				{
					mini = abs(getint(ss) - getint(tt));
					anss = ss;
					anst = tt;
				}
				
				s[i] = '0';
				t[i] = '0';
			}
			else if (s[i] == '?')
			{
				if (t[i] > '0')
				{
					s[i] = (char)(t[i] - 1);
					string ss = sfill(s, '9'), tt = sfill(t, '0');
					if (abs(getint(ss) - getint(tt)) < mini || (abs(getint(ss) - getint(tt)) == mini && mp(anss, anst) > mp(ss, tt)))
					{
						mini = abs(getint(ss) - getint(tt));
						anss = ss;
						anst = tt;
					}
				}
				if (t[i] < '9')
				{
					s[i] = (char)(t[i] + 1);
					string ss = sfill(s, '0'), tt = sfill(t, '9');
					if (abs(getint(ss) - getint(tt)) < mini || (abs(getint(ss) - getint(tt)) == mini && mp(anss, anst) > mp(ss, tt)))
					{
						mini = abs(getint(ss) - getint(tt));
						anss = ss;
						anst = tt;
					}
				}
				
				s[i] = t[i];
			}
			else if (t[i] == '?')
			{
				if (s[i] > '0')
				{
					t[i] = (char)(s[i] - 1);
					string ss = sfill(s, '0'), tt = sfill(t, '9');
					if (abs(getint(ss) - getint(tt)) < mini || (abs(getint(ss) - getint(tt)) == mini && mp(anss, anst) > mp(ss, tt)))
					{
						mini = abs(getint(ss) - getint(tt));
						anss = ss;
						anst = tt;
					}
				}
				if (s[i] < '9')
				{
					t[i] = (char)(s[i] + 1);
					string ss = sfill(s, '9'), tt = sfill(t, '0');
					if (abs(getint(ss) - getint(tt)) < mini || (abs(getint(ss) - getint(tt)) == mini && mp(anss, anst) > mp(ss, tt)))
					{
						mini = abs(getint(ss) - getint(tt));
						anss = ss;
						anst = tt;
					}
				}
				
				t[i] = s[i];
			}
		}
		
		string ss = sfill(s, '0' ), tt = sfill(t, '9');
		if (abs(getint(ss) - getint(tt)) < mini || (abs(getint(ss) - getint(tt)) == mini && mp(anss, anst) > mp(ss, tt)))
		{
			mini = abs(getint(ss) - getint(tt));
			anss = ss;
			anst = tt;
		}
		
		cout << anss << " " << anst << "\n";
	}
	return 0;
}
