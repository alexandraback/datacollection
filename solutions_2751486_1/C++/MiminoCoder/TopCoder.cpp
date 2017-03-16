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

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int MAX = 1000007;
char in[MAX];
int len, n, cons[MAX];

string bad = "aeiou";
bool check(char c)
{
	REP(i, bad.size())
		if (c == bad[i])
			return false;
	return true;
}

void Solve(int tc)
{
	scanf("%s%d", in, &n);
	len = strlen(in);
	REP(i, len)
	{
		if (check(in[i]))
			cons[i] = (i ? cons[i-1] : 0) + 1;
		else
			cons[i] = 0;
	}

	ll res = 0;
	int right = 0;
	priority_queue<pair<int, int> > manage;

	REP(i, len)
	{
		while (manage.size())
		{
			pair<int, int> temp = manage.top();
			if (temp.second < i || (temp.second+1 < right && check(in[temp.second+1])))
				manage.pop();
			else if (temp.second-i+1 < temp.first)
			{
				manage.pop();
				temp.first = temp.second-i+1;
				manage.push(temp);
			}
			else
				break;
		}
		while (right < len && (manage.empty() || manage.top().first < n))
		{
			pair<int, int> temp;
			temp.first = min(right-i+1, cons[right]);
			temp.second = right;
			++right;
			manage.push(temp);
		}
		if (manage.top().first >= n)
			res += len-right+1;
	}
	
	printf("Case #%d: %lld\n", tc, res);
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}