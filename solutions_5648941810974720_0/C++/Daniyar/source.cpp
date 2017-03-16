//g++ -std=c++0x your_file.cpp -o your_program
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#define fname ""
#define mp make_pair
#define F first
#define pb push_back
#define S second
#define ub upper_bound
#define lb lower_bound
#define inf 2000000000
#define INF 2000000000000000000ll
using namespace std;

const int maxn = 2020;

char s[maxn];

int cnt[333];

vector <int> ans;

inline void Proceed(int x, string s, char ch)
{
	int ln = cnt[(int)ch];
	for (int i = 0; i < ln; i++)
		ans.pb(x);
	for (int i = 0; i < (int)s.length(); i++)
		cnt[(int)s[i]] -= ln;
}

inline void solve()
{
	gets(s);
	int n = (int)strlen(s);
	memset(cnt, 0, sizeof(cnt));
	ans.clear();
	for (int i = 0; i < n; i++)
		cnt[(int)s[i]]++;
	Proceed(0, "ZERO", 'Z');
	Proceed(2, "TWO", 'W');
	Proceed(4, "FOUR", 'U');
	Proceed(6, "SIX", 'X');
	Proceed(3, "THREE", 'R');
	Proceed(8, "EIGHT", 'H');
	Proceed(5, "FIVE", 'F');
	Proceed(7, "SEVEN", 'V');
	Proceed(9, "NINE", 'I');
	Proceed(1, "ONE", 'O');
	sort (ans.begin(), ans.end());
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d", ans[i]);
	puts("");
}

int main()
{
	freopen (fname"input.txt", "r", stdin);
	freopen (fname"output.txt", "w", stdout);
	int T;
	cin >> T;
	scanf("\n");
	for (int Case = 1; Case <= T; Case++)
	{
		printf("Case #%d: ", Case);
		solve();
	}
	return 0;
}
