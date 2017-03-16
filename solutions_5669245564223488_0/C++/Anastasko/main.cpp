//#pragma comment(linker, "/STACK:134217728")
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define INF 1000000007
#define y1 agaga
#define ll long long
#define ull unsigned long long


int t;
int n;
string s[11];
bool can[11][11];

bool ok(string a)
{
	int was[33];

	FOR(i, 0, 33)
		was[i] = 0;

	a += '0';

	FOR(i, 1, a.size())
	if (a[i] != a[i - 1])
	{
		if (was[a[i - 1] - 'a'] == 1) return false;

		was[a[i - 1] - 'a'] = 1;
	}

	return true;
}

string S;

string f(string s)
{
	string t="";

	s += '0';

	FOR(i, 1, s.size())
	if (s[i] != s[i - 1])
		t += s[i - 1];

	return t;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> t;

	FOR(T,1,t+1)
	{
		cerr << T << endl;
		int sol = 0;

		cin >> n;

		FOR(i, 0, n)
		{
			cin >> s[i];
			s[i] = f(s[i]);
		}

	

		int p[11];

		FOR(i, 0, n)
			p[i] = i;

		do
		{
			
			S = "";

			FOR(i, 0, n)
			{
					S += s[p[i]];
			}

			if (ok(S)) sol++;

		} while (next_permutation(p, p + n));

		cout << "Case #" << T << ": " << sol << endl;
	}

	return 0;
}