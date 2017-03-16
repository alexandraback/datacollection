#include <vector>
#include <map>
#include <set>
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
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
#define INF 2147483647
typedef long long ll;
typedef pair<int, int> ii;
template <class T> int size(T x) { return x.size(); }

int main()
{
	int maxscore[2][31];
	memset(maxscore[0], 0, 31 << 2);
	memset(maxscore[1], 0, 31 << 2);

	for (int a = 0; a <= 10; a++)
	{
		for (int b = 0; b <= 10; b++)
		{
			for (int c = 0; c <= 10; c++)
			{
				int sum = a + b + c,
					mx = max(a, max(b, c)),
					mn = min(a, min(b, c));

				if (mx - mn <= 1 && mx > maxscore[0][sum]) maxscore[0][sum] = mx;
				if (mx - mn == 2 && mx > maxscore[1][sum]) maxscore[1][sum] = mx;
			}
		}
	}

	/*for (int s = 0; s <= 30; s++)
	{
		if (maxscore[0][s] > maxscore[1][s]) printf("%d\n", s);
	}

	return 0;*/

	int ts;
	scanf("%d\n", &ts);

	int sums[100];
	for (int t = 0; t < ts; t++)
	{
		int N, S, p;
		scanf("%d %d %d", &N, &S, &p);
		for (int i = 0; i < N; i++) scanf("%d", sums + i);

		int cnt = 0, cnt2 = 0;
		for (int i = 0; i < N; i++)
		{
			if (maxscore[0][sums[i]] >= p) cnt++;
			else if (maxscore[1][sums[i]] >= p) cnt2++;
		}

		printf("Case #%d: %d\n", t + 1, cnt + min(cnt2, S));
	}

	return 0;
}