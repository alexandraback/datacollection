#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef long long lint;

int main()
{
	int ntest;

	scanf("%d", &ntest);

	for (int t = 0; t < ntest; t++) {
		lint n;
		lint x, y;

		scanf("%lld %lld %lld", &n, &x, &y);
		n--;

		lint dist = (llabs(x) + llabs(y))/2;
		lint lastl, putatlast;

		for (lint l = 1;; l += 2) {
			if (n < 2*l - 1) {
				lastl = l;
				putatlast = n+1;
				break;
			}
			n -= 2*l-1;
		}

		lint pl = 2*dist+1, ph = y;

//		printf("Pl = %d\n", pl);

		long double result;

		if (pl < lastl) {
			result = 1.0;
		} else if (pl > lastl) {
			result = 0.0;
		} else {
			lint l = lastl;
			lint max = 2*l-1;
			lint many = putatlast;
			lint want = ph+1;

			if (many == max)
				result = 1.0;
			else if (want == l)
				result = 0.0;
			else {
				lint maxeach = l-1;
				long double p2 = 1;
				long double binom = 1;

				for (int i = 0; i < many; i++)
					p2 /= 2.0;

				result = 0.0;

//				printf("Want = %d, many = %d\n", want, many);

				for (lint tl = 0; tl <= many; tl++) {
					long double prob = binom * p2;

					binom *= (many-tl)/(tl+1.0);
					
					lint left = tl, right = many-tl;

					if (left > maxeach) {
						lint delta = left-maxeach;
						left -= delta;
						right += delta;
					} else if (right > maxeach) {
						lint delta = right-maxeach;
						right -= delta;
						left += delta;
					}

//					printf("Tl = %d, left = %d, right = %d\n", tl, left, right);

					if (left >= want)
						result += prob;
				}
			}
		}

//		printf("Last side is l=%lld, receiving %lld\n", lastl, n+1);
//		printf("Pl = %lld, Ph = %lld\n", pl, ph);

		printf("Case #%d: %.7f\n", t+1, (double)result);
	}

	return 0;
}
