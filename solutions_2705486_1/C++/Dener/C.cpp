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

const int MAXLEN = 4000;
const int MAXSHIFT = 6;

const int inf = 1<<20;

const int DSIZE = 521196;

char dict[DSIZE][12];
int length[DSIZE];

void init() {
	freopen("dict.txt","r", stdin);
	for (int i = 0; i < DSIZE; i++)
	{
		scanf("%s", dict[i]);
		length[i] = strlen(dict[i]);
	}
}

char str[MAXLEN];
int n;

int ans[MAXLEN][MAXSHIFT];

void solve() {
	scanf("%s", str);
	int n = strlen(str);

	for (int i = 0; i < MAXLEN; i++)
		for (int j = 0; j < MAXSHIFT; j++)
			ans[i][j] = inf;

	ans[0][0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAXSHIFT; j++)
		{
			if (ans[i][j] == inf)
				continue;

			int lasterr = j - 1;

			if (lasterr == -1)
				lasterr = -100;
			else
				lasterr = i - 1 - lasterr;

			for (int nextword = 0; nextword < DSIZE; nextword++) {
				int cur = lasterr;
				bool ok = true;
				int errcount = 0;
				int nextlen = length[nextword];
				char *sd = dict[nextword];
				char *ss = str + i;
				for (int q = 0; q < nextlen && ok; q++, sd++, ss++) {
					if (*ss != *sd) {
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
				else
					cur = (i + nextlen - 1) - cur;
				if (cur >= 5)
					cur = -1;
				if (ans[i + nextlen][cur + 1] > ans[i][j] + errcount)
					ans[i + nextlen][cur + 1] = ans[i][j] + errcount;
			}
		}
	}

	int bestans = inf;
	for (int j = 0; j < MAXSHIFT; j++)
		bestans = min(bestans, ans[n][j]);
	printf("%d\n", bestans);
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
