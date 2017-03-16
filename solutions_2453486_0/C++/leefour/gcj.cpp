#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long int64;
const double pi = acos (-1.0);
const double eps = 1.0e-10;

char check(char a, char b, char c, char d)
{
	map <char, int> cm;
	cm[a]++;
	cm[b]++;
	cm[c]++;
	cm[d]++;
	if (cm['X'] == 4 || (cm['X'] == 3 && cm['T'] == 1))
		return 'X';
	if (cm['O'] == 4 || (cm['O'] == 3 && cm['T'] == 1))
		return 'O';
	return -1;
}

void solve()
{
	char g[4][5];
	char res = -1;
	bool complete = true;
	for (int i = 0; i < 4; ++i) {
		scanf("%s", g[i]);
		if (res == -1)
			res = check(g[i][0], g[i][1], g[i][2], g[i][3]);
		for (int j = 0; j < 4; ++j)
			if (g[i][j] == '.')
				complete = false;
	}
	for (int i = 0; i < 4; ++i) {
		if (res == -1)
			res = check(g[0][i], g[1][i], g[2][i], g[3][i]);
	}
	if (res == -1)
		res = check(g[0][0], g[1][1], g[2][2], g[3][3]);
	if (res == -1)
		res = check(g[0][3], g[1][2], g[2][1], g[3][0]);
	if (res == 'X')
		printf("X won\n");
	if (res == 'O')
		printf("O won\n");
	if (res == -1 && complete)
		printf("Draw\n");
	if (res == -1 && !complete)
		printf("Game has not completed\n");
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	for (int icase = 1; icase <= ncase; ++icase) {
		printf("Case #%d: ", icase);
		solve();
	}
}
