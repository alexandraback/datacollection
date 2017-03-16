#include <iostream>
using namespace std;

const int CNT = 10100;
//const int CNT = 100;
double prob[2 * CNT + 10][CNT + 10];



double getAns(int all, int side, int need)
{
	if (need > side)
	{
		return (all == need + side) ? 1 : 0;
	}
	double ans = 0;
	
	for (int i = 0; i < all - side; i++)
		ans += prob[all][i];

	for (int i = need; i <= side; i++)
	{
		ans += prob[all][i];
	}
	return ans;
}


void init()
{
	prob[0][0] = 1;
	for (int i = 0; i < 2 * CNT; i++)
	{
		for (int j = 0; j <= i && j < CNT; j++)
		{
			prob[i + 1][j] += 0.5 * prob[i][j];
			prob[i + 1][j + 1] += 0.5 * prob[i][j];
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	init();

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		x = abs(x);
		int cntNeed = y + 1;
		int diag = (x + y) / 2;

		int curCnt = 1;
		int sumN = 0;

		for (int i = 0; i < diag; i++)
		{
			sumN += curCnt;
			curCnt += 4;
			if (sumN > n)
				break;
		}
		double prob = 0;
		int failed = n - sumN;
		if (failed > 0)
		{
			int maxOneSide = curCnt / 2;
			if (maxOneSide + cntNeed <= failed)
			{
				prob = 1;
			}
			else
			{
				prob = getAns(failed, maxOneSide, cntNeed);
			}
		}
		printf("Case #%d: %.8lf\n", t + 1, prob);
	}




	return 0;
}