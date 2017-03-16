#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

const int INF = 1 << 29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

const ll MOD = 1000000007;
const int MAX = 101;
ll fact[MAX];

int N, same[30];
bool used[MAX];
string in[MAX];

void Solve(int tc)
{
	memset(same, 0, sizeof(same));
	memset(used, 0, sizeof(used));

	cin >> N;
	REP(i, N)
	{
		string s;
		cin >> s;
		in[i] = s;
		if (s[0] == s[s.size() - 1])
			++same[s[0] - 'a'];
	}

	// join same endings
	bool found = true;
	while (found)
	{
		found = false;
		REP(i, N)
		{
			if (used[i] || in[i][0] != in[i].back()) continue;
			REP(j, N)
			{
				if (i == j || used[j]) continue;
				if (in[j][0] == in[i][0])
				{
					in[j] = in[i] + in[j];
					used[i] = true;
					found = true;
					goto FOUND;
				}
				if (in[j].back() == in[i][0])
				{
					in[j] = in[j] + in[i];
					used[i] = true;
					found = true;
					goto FOUND;
				}
			}
		}
	FOUND:
		;
	}
	// join different endings
	found = true;
	while (found)
	{
		found = false;
		REP(i, N)
		{
			if (used[i]) continue;
			REP(j, N)
			{
				if (i == j || used[j]) continue;
				if (in[i].back() == in[j][0])
				{
					in[i] += in[j];
					used[j] = true;
					found = true;
					goto FOUND2;
				}
			}
		}
	FOUND2:
		;
	}

	int cnt = 0;
	string s;
	REP(i, N)
	{
		if (!used[i])
		{
			s += in[i];
			++cnt;
		}
	}
	ll res = fact[cnt];
	REP(i, 30)
		res = (res * fact[same[i]]) % MOD;

	bool ok = true;
	int visited = 0;
	REP(i, s.size())
	{
		if (test(visited, s[i] - 'a')) ok = false;
		visited |= two(s[i] - 'a');
		while (i + 1 < s.size() && s[i] == s[i + 1])
			++i;
	}
	printf("Case #%d: %lld\n", tc, ok ? res : 0LL);
}

int main()
{
	fact[0] = 1;
	FOR(i, 1, MAX - 1)
		fact[i] = (fact[i - 1] * i) % MOD;
	int T;
	scanf("%d\n", &T);
	FOR(tc, 1, T) Solve(tc);

	return 0;
}