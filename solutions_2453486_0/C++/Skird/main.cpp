#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

using namespace std;

typedef long long ll;
typedef long double lf;

const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

char data[4][5];

string solve()
{
	for (int i = 0; i < 4; i++) scanf("%s\n", data[i]);
	scanf("\n");
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int d = 0; d < 8; d++)
			{
				int c = 0, z = 0, t = 0;
				for (int k = 0; k < 4; k++)
				{
					int x = i + dx[d] * k, y = j + dy[d] * k;
					if (x < 0 || x >= 4 || y < 0 || y >= 4) break;
					if (data[x][y] == 'X') c++;
					if (data[x][y] == 'O') z++;
					if (data[x][y] == 'T') t++;
				}
				if (c >= 3 && c + t == 4) return "X won";
				if (z >= 3 && z + t == 4) return "O won";
			}
	int cnt = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (data[i][j] == '.') cnt++;
	if (cnt) return "Game has not completed";
	else return "Draw";
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; i++) cout << "Case #" << i + 1 << ": " << solve() << endl;
	return 0;
}
