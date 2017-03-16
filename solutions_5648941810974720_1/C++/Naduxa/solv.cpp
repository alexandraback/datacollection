#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <string>
#include <map>
#include <time.h>

using namespace std;
const int N = 16;
vector<pair<string, string>> g;

int dp[(1 << N)];
int n;


int yes(int mask, int j) {
	bool f1 = false;
	bool f2 = false;
	for (int i = 0; i < n; i++) {
		if (i == j) continue;
		if (g[i].first == g[j].first && ((mask & (1 << i)) == 0))
		{
			f1 = true;
		}
		if (g[i].second == g[j].second && ((mask & (1 << i)) == 0))
		{
			f2 = true;
		}
	}
	if (f1 && f2)
		return true;
	return false;
}

int calc(int mask) {
	if (dp[mask] != -1)
		return dp[mask];
	if (mask == 0) {
		return dp[mask] = 0;
	}

	dp[mask] = 0;
	for (int i = 0; i < n; i++) {
		if ((mask & (1 << i)) != 0) {
			int r = yes(mask, i);
			dp[mask] = max(dp[mask], calc(mask ^ (1 << i)) + r);
		}
	}
	return dp[mask];
}

int solve() {
	memset(dp, -1, sizeof dp);
	return calc((1 << n) - 1);
}
string num[10] = {
	"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

string get(string s) {
	map<char, int> cnt;
	for (int i = 0; i < s.length(); i++) {
		cnt[s[i]]++;
	}
	int ans[10];
	for (int i = 0; i < 10; i++)
		ans[i] = 0;

	ans[0] = cnt['Z'];
	for (int i = 0; i < num[0].length(); i++)
		cnt[num[0][i]] -= ans[0];
	ans[2] = cnt['W'];
	for (int i = 0; i < num[2].length(); i++)
		cnt[num[2][i]] -= ans[2];
	ans[4] = cnt['U'];
	for (int i = 0; i < num[4].length(); i++)
		cnt[num[4][i]] -= ans[4];
	ans[6] = cnt['X'];
	for (int i = 0; i < num[6].length(); i++)
		cnt[num[6][i]] -= ans[6];
	ans[7] = cnt['S'];
	for (int i = 0; i < num[7].length(); i++)
		cnt[num[7][i]] -= ans[7];
	ans[8] = cnt['G'];
	for (int i = 0; i < num[8].length(); i++)
		cnt[num[8][i]] -= ans[8];
	ans[1] = cnt['O'];
	for (int i = 0; i < num[1].length(); i++)
		cnt[num[1][i]] -= ans[1];
	ans[9] = cnt['N'] / 2;
	for (int i = 0; i < num[9].length(); i++)
		cnt[num[9][i]] -= ans[9];
	ans[3] = cnt['H'];
	for (int i = 0; i < num[3].length(); i++)
		cnt[num[3][i]] -= ans[3];
	ans[5] = cnt['F'];
	for (int i = 0; i < num[5].length(); i++)
		cnt[num[5][i]] -= ans[5];

	string gg = "";
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < ans[i]; j++)
			gg += char(i + '0');
	return gg;
}

int main() {
#ifdef _DEBUG
	freopen("kuku.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	freopen("a2.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin.tie(0);
	cout.sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		
		cout << "Case #" << i + 1 << ": ";
		cout << get(s) << endl;
	}
	return 0;
}