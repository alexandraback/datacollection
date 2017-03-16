#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <memory.h>
#include <iterator>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
#define sz(m) ((m).size())
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0,i##e=n;i<i##e;++i)
#define fori(i,m) forn(i,sz(m))
#define each(i,m) for(typeof(m.begin())i=m.begin(),i##e=m.end();i!=i##e;++i)
#define srt(s) sort(all(s))
#define maxup(a,b) a=max(a,b)
#define minup(a,b) a=min(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second


long long solve(const string& s, int n)
{
	int ccg = 0;
	long long result = 0;
	int len = s.length();
	int cgl = -1;
	for (int i = len - 1; i >= 0; --i) {
		if (s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i') {
			ccg = 0;
		} else {
			++ccg;
			if (ccg >= n) {
				cgl = i + n - 1;
			}
		}
		result += cgl < 0 ? 0 : len - cgl;
	}
	return result;
}

int main()
{
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		string s;
		int n;
		cin >> s >> n;
		cout << "Case #" << test << ": " << solve(s, n) << endl;
	}
}
