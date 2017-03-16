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
	int ts;
	scanf("%d\n", &ts);
	for (int t = 0; t < ts; t++)
	{
		int a, b;
		scanf("%d %d\n", &a, &b);
		vector<double> ok(a);
		for (int i = 0; i < a; i++) scanf("%lf", &(ok[i]));

		double min;

		for (int bs = 0; bs <= a; bs++)
		{
			double sum = 0.0;

			for (int i = 0; i < (1 << a); i++)
			{
				bool any = false;
				double prob = 1.0;
				for (int j = 0; j < a; j++)
				{
					if (i & (1 << j))
					{
						prob *= ok[j];
					}
					else
					{
						prob *= (1 - ok[j]);
						if (j < a - bs) any = true;
					}
				}

				int cnt = bs;
				cnt += b - (a - bs) + 1;
				if (any) cnt += b + 1;
				sum += prob * cnt;
			}

			if (bs == 0 || sum < min) min = sum;
		}

		int cnt2 = 1 + b + 1;
		if (cnt2 < min) min = cnt2;
		printf("Case #%d: %0.6lf\n", t + 1, min);
	}

	return 0;
}