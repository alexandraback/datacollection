#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <string>
#include <fstream>

using namespace std;

#define ll long long

const int MN = 100;
const int inf = (1 << 29);
const int delt = 5;

int dp[MN][MN];

vector <string> vs;
string str;

void load() {
	vs.reserve(521196);
	//ifstream in("garbled_email_dictionary.txt");
	freopen("garbled_email_dictionary.txt", "r", stdin);
	/*string s;
	while (cin >> s)
		vs.push_back(s);*/
	char s[100];
	while (scanf("%s", s) != EOF) {
		int len = strlen(s);
		string tmp(s, s + len);
		vs.push_back(tmp);
	}
	//in.close();
}

int relax(int &pos, int &last, string &s) {
	if (pos + s.size() - 1 >= str.size())
		return inf;
	int ans = 0;
	for(int i = 0; i < s.size(); i ++) {
		if (str[pos + i] != s[i]) {
			if (pos + i - last >= 5) {
				ans ++;
				last = pos + i;
			}
			else
				return inf;
		}
	}
	pos += s.size();
	return ans;
}

int main()
{
	load();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for(int k = 0; k < t; k ++) {
		cin >> str;
		int n = str.size();
		fill(&dp[0][0], &dp[0][0] + MN * MN, inf);
		dp[0][0] = 0;
		for(int pos = 0; pos < n; pos ++) {
			for(int last = -delt; last < n; last ++) {
				if (dp[pos][last + delt] == inf)
					continue;
				for(int i = 0; i < vs.size(); i ++) {
					int npos = pos;
					int nlast = last;
					int x = relax(npos, nlast, vs[i]);
					dp[npos][nlast + delt] = min(dp[npos][nlast + delt], dp[pos][last + delt] + x);
				}
			}
		}
		int ans = inf;
		for(int last = -5; last < n; last ++)
			ans = min(ans, dp[n][last + delt]);
		printf("Case #%d: %d\n", k + 1, ans);
	}
	return 0;
}