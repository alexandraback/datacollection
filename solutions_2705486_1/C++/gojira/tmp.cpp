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
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int dp[4001][5];

struct TrieNode
{
	vector<TrieNode*> child;
	char c;
	bool end;
	TrieNode(char c)
	{
		this -> c = c;
		end = false;
	}
};

TrieNode* root;

pair<int, int> check(const string &s, int pos, const string &t, int lst)
{
	if (pos + t.length() > s.length())
		return make_pair(-1, 0);
	int ret = 0;
	int last = -5 + lst;
	for(int i = 0; i < t.length(); i++)
	{
		if (s[pos + i] == t[i]) continue;
		if (i - last < 5)
			return make_pair(-1, 0);
		last = i;
		++ret;
	}
	return make_pair(ret, max(last - (int)t.length() + 5, 0));
}

TrieNode* getChild(TrieNode* cur, char c)
{
	for(int i = 0; i < cur -> child.size(); i++)
		if (cur -> child[i] -> c == c)
			return cur -> child[i];
	cur -> child.push_back(new TrieNode(c));
	return cur -> child.back();
}

void killerDFS(TrieNode* cur)
{
	for(int i = 0; i < cur -> child.size(); i++)
		killerDFS(cur -> child[i]);
	delete cur;
}

void process(const string &s, int pos, int last, int cost, TrieNode* cur)
{
	if (cur -> end)
		if (dp[pos][last] == -1 || dp[pos][last] > cost)
			dp[pos][last] = cost;
	if (pos == s.length()) return ;
	for(int i = 0; i < cur -> child.size(); i++)
	{
		if (cur -> child[i] -> c == s[pos])
			process(s, pos + 1, max(0, last - 1), cost, cur -> child[i]);
		else
			if (last == 0)
				process(s, pos + 1, 4, cost + 1, cur -> child[i]);
	}
}

int main()
{
	freopen("dict.txt", "r", stdin);
	root = new TrieNode('-');
	for(int i = 0; i < 521196 ; i++)
	{
		string s;
		cin >> s;
		TrieNode* cur = root;
		for(int j = 0; j < s.length(); j++)
			cur = getChild(cur, s[j]);
		cur -> end = true;
	}

	double st = 1.0 * clock() / CLOCKS_PER_SEC;
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, k, n, T, a;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		string s;
		cin >> s;
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for(i = 0; i < s.length(); i++)
			for(int last = 0; last < 5; last++)
			{
				if (dp[i][last] == -1) continue;
				process(s, i, last, dp[i][last], root);
			}
		int ans = (int)1e9;
		for(i = 0; i < 5; i++)
			if (dp[s.length()][i] != -1)
				ans = min(ans, dp[s.length()][i]);
		printf("Case #%d: %d\n", t, ans);
	}
	printf("%lf\n", 1.0 * clock() / CLOCKS_PER_SEC - st);

	killerDFS(root);

	return 0;
}