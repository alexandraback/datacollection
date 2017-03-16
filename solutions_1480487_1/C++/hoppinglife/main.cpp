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

const double e = 1e-12;

using namespace std;

int T;

int main() {
	freopen("result.in","r",stdin);
	freopen("result.out","w",stdout);
	scanf("%d",&T);

	for(int i=0;i<T;i++) {
		int N;
		int score[210];
		int sum = 0;
		scanf("%d",&N);
		for(int j=0;j<N;j++) {
			scanf("%d",&score[j]);
			sum += score[j];
		};

		printf("Case #%d:",i+1);

		for (int j = 0; j < N; j++)
		{
			double l = 0;
			double r = 1;
			double k;
			while (l < r - e)
			{
				k = (l + r) / 2;
				double x1 = sum * k;
				double x2 = sum - x1;
				x1 += score[j];
				for (int kxx = 0; kxx < N; kxx++)
					if (kxx != j && x1 > score[kxx])
						x2 -= x1 - score[kxx];
				if (x2 < e)
					r = k;
				else
					l = k;
			}
			printf(" %.8lf",k * 100);
		}
		printf("\n");
	}

	return 0;
}