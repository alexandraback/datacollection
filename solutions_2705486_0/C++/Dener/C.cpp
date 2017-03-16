#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

const int MAXLEN = 60;

const int inf = 1<<20;

vector< string > dict;

void init() {
	freopen("dict.txt","r", stdin);
	string s;
	for (int i = 0; i < 521196; i++)
	{
		cin >> s;
		dict.push_back(s);
	}
}

string str;
int n;

int ans[MAXLEN][MAXLEN];

void solve() {
	cin >> str;
	n = str.size();

	for (int i = 0; i < MAXLEN; i++)
		for (int j = 0; j < MAXLEN; j++)
			ans[i][j] = inf;

	ans[0][0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n+3; j++)
		{
			if (ans[i][j] == inf)
				continue;

			int lasterr = j - 1;

			if (lasterr == -1)
				lasterr = -100;

			for (int nextword = 0; nextword < dict.size(); nextword++) {
				int cur = lasterr;
				bool ok = true;
				int errcount = 0;
				int nextlen = dict[nextword].size();
				for (int q = 0; q < nextlen && ok; q++) {
					if (str[i + q] != dict[nextword][q]) {
						errcount++;
						if (i + q - cur < 5)
							ok = false;
						cur = i + q;
					}
				}

				if (!ok)
					continue;

				if (cur == -100)
					cur = -1;
				ans[i + nextlen][cur + 1] = min(
				ans[i + nextlen][cur + 1],
				ans[i][j] + errcount);
			}
		}
	}

	int bestans = inf;
	for (int j = 0; j < n+3; j++)
		bestans = min(bestans, ans[n][j]);
	cout << bestans << endl;
}

int main() {
	init();
#ifndef ONLINE_JUDGE
	freopen("C_input.txt","r", stdin);
	freopen("C_output.txt","w", stdout);
#endif

	int testnum;
	scanf("%d\n", &testnum);
	for (int i = 0; i < testnum; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}
}
