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
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double mas[2][1010];

int main ()
{
	freopen ("input.txt","rt",stdin);
	freopen ("output.txt","wt",stdout);
	int test;

	scanf ("%d",&test);
	for (int step=1;step<=test;step++)
	{
		int n, i, j, war_win, dec_war_win;
		scanf("%d", &n);
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < n; j++) scanf("%lf", &mas[i][j]);
		}

		sort(mas[0], mas[0] + n);
		sort(mas[1], mas[1] + n);

		j = 0;
		for (i = 0; i < n; i++)
		{
			while (j < n && mas[1][j] < mas[0][i])j++;
			if (j == n) break;
			j++;
		}

		war_win = n - i;

		j = 0;
		for (i = 0; i < n; i++)
		{
			while (j < n && mas[0][j] < mas[1][i])j++;
			if (j == n) break;
			j++;
		}

		dec_war_win = i;

		printf("Case #%d: %d %d\n", step, dec_war_win, war_win);
	}

	return 0;
}