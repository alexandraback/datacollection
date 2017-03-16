#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<functional>
#include<cstdlib>
#include<list>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

string s[100];
string now;
bool f[100];
int test, n, ans;

bool check(string s) {
	int c[26];
	memset(c, 0, sizeof c);
	for (int i = 0; i < s.length(); ++ i) {
		if (! i) c[s[i] - 'a'] ++;
		else {
			if (s[i] != s[i-1] && c[s[i] - 'a'])
				return 0;
			c[s[i] - 'a'] ++;
		}
	}
	return 1;
}

void dfs(int x)
{
	if (x == n)
	{
		ans += check(now);
		return;
	}
	for (int i = 0; i < n; ++ i)
		if (! f[i]) 
		{
			f[i] = 1;
			now += s[i];
			dfs(x + 1);
			now = now.substr(0, now.length() - s[i].length());
			f[i] = 0;
		}
}

string clean(string s) {
	string st = "";
	for (int i = 0; i < s.length(); ++ i)
		if (! i || s[i] != s[i-1]) 
			st += s[i];
	return st;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("my.out","w",stdout);
	scanf("%d",&test);
	for (int t = 1; t <= test; ++ t) {
		cerr << t << endl;
		printf("Case #%d: ", t);
		scanf("%d",&n);
		for (int i = 0; i < n; ++ i) {
			cin >> s[i];
			s[i] = clean(s[i]);
		}
		memset(f, 0, sizeof f);
		ans = 0;
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}