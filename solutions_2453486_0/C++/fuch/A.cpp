#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <functional>

#define rep(i,n) for(int i=0;i<(n);++i)
#define foreach(i,v) for(__typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define ass(v) (v)||++*(int*)0;

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<double> VD;

char b[4][5];
const char *ans[] = {"X won", "O won", "Draw", "Game has not completed"};

void add(int ch, int &X, int &O)
{
	if (ch == 'T')
	{
		++X;
		++O;
	}
	else if (ch == 'X') ++X;
	else if (ch == 'O') ++O;
}
int check()
{
	int X = 0, O = 0;
	for (int i = 0; i < 4; ++i) add(b[i][i], X, O);
	if (X == 4) return 0;
	if (O == 4) return 1;

	X = 0;
	O = 0;
	for (int i = 0; i < 4; ++i) add(b[i][3 - i], X, O);
	if (X == 4) return 0;
	if (O == 4) return 1;

	for (int i = 0; i < 4; ++i)
	{
		X = 0;
		O = 0;
		for (int j = 0; j < 4; ++j) add(b[i][j], X, O);
		if (X == 4) return 0;
		if (O == 4) return 1;
	}

	for (int i = 0; i < 4; ++i)
	{
		X = 0;
		O = 0;
		for (int j = 0; j < 4; ++j) add(b[j][i], X, O);
		if (X == 4) return 0;
		if (O == 4) return 1;
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			if (b[i][j] == '.') return 3;
	}

	return 2;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs)
	{
		for (int i = 0; i < 4; ++i)
		{
			scanf("%s", b[i]);
		}
		int ret = check();
		printf("Case #%d: %s\n", cs, ans[ret]);

	}
	return 0;
}
