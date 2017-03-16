# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <math.h>
# include <algorithm>
# include <string.h>
# include <stack>
# include <queue>
# include <sstream>
# include <set>
# include <map>
# include <assert.h>
using namespace std;

const int alphabet = 27;
struct vertex
{
	int next[alphabet];
	bool leaf;
};

vector<vertex> t;
int size;

const int wordsNum = 521196;
const int maxnLen = 10;

void add_string (const string & s) {
	int v = 0;
	for (size_t i=0; i<s.length(); ++i) {
		char c = s[i]-'a'; 
		if (t[v].next[c] == -1) {
			vertex vert;
			vert.leaf = false;
			memset (vert.next, -1, sizeof(vert.next));
			t.push_back(vert);
			t[v].next[c] = size++;
		}
		v = t[v].next[c];
	}
	t[v].leaf = true;
}

const int maxss = 5555;
const int inf = 99999999;
int dp[maxss];

char curString[15];
int curLen;

int otvety[15];

void dfs(int strPos, int treePos, int changed)
{
	if (t[treePos].leaf && changed < otvety[strPos])
		otvety[strPos] = changed;
	if (strPos == curLen)
		return;

	for (char ch = 'a'; ch <= 'z'; ch++)
		if ((abs(ch - curString[strPos]) >= 5) && t[treePos].next[ch - 'a'] != -1)
			dfs(strPos + 1, t[treePos].next[ch - 'a'], changed + 1);
	if (t[treePos].next[curString[strPos] - 'a'] != -1)
		dfs(strPos + 1, t[treePos].next[curString[strPos] - 'a'], changed);
}

int main()
{
	//ios_base::sync_with_stdio(false);
	ofstream cout ("output.txt");
	ifstream cin ("garbled_email_dictionary.txt");
	vertex root;
	root.leaf = false;
	memset(root.next, -1, sizeof(root.next));
	t.push_back(root);
	size++;
	for (int i = 0; i < wordsNum; i++)
	{
		string s;
		cin >> s;
		add_string(s);
	}
	cin.close();
	
	system("pause");

	cin.open("input.txt");

	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++)
	{
		string s;
		cin >> s;
		for (int i = 0; i < maxss; i++)
			dp[i] = inf;
		dp[0] = 0;

		for (int i = 0; i < s.length(); i++)
		{
			int pos = 0;
			for (int j = 0; j < 12 && i + j < s.length(); j++)
				curString[pos++] = s[i + j];
			curLen = pos;
			for (int i = 0; i < 15; i++)
				otvety[i] = inf;
			dfs(0, 0, 0);
			for (int j = 1; j <= pos; j++)
				dp[i + j] = min(dp[i + j], dp[i] + otvety[j]);
		}

		int ans = dp[s.length()];

		cout << "Case #" << test + 1 << ": " << ans << endl;
	}


	//system("pause");
	return 0;
}
