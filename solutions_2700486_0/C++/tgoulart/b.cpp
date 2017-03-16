#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

double calc(int n, int limit, int l, int r, int Y, double p) {
    if (n == 0) {
        if (Y <= r - 1) {
            return p;
        }
        return 0.0;
    }
    assert(l < limit || r < limit);
    double ans = 0.0;
    if (l < limit) {
        ans += calc(n - 1, limit, l + 1, r, Y, p * ((r < limit) ? 0.5 : 1.0));
    }
    if (r < limit) {
        ans += calc(n - 1, limit, l, r + 1, Y, p * ((l < limit) ? 0.5 : 1.0));
    }
    return ans;
}

double p_small(int n, int limit, int Y) {
    return calc(n, limit, 0, 0, Y, 1.0);
}

int main() {
	int T = 1;
    int t;

    scanf("%d", &t);
    while (t--) {
        int N, X, Y;
        scanf("%d %d %d", &N, &X, &Y);
        if (X < 0) X = -X;

        double ans = 1.0;

        if (X != 0 || Y != 0) {
            int k_goal = (X + Y) / 2 + 1;

            for (int k=1; true; ++k) {
                int amount1 = k * (2 * k - 1);
                int amount2 = (k + 1) * (2 * (k + 1) - 1);

                if (amount2 < N) {
                    // keep summing
                    continue;
                }

                if (k_goal <= k) {
                    ans = 1.0;
                }
                else if (k_goal > k + 1) {
                    ans = 0.0;
                }
                else {
                    assert(k_goal == k + 1);
                    if (amount2 == N) {
                        ans = 1.0;
                    }
                    else {
                        int diamondsLeft = N - amount1;
//                        printf("%d %d\n", diamondsLeft, k);
                        assert(amount1 + 2 * k * 2 + 1 == amount2);
                        ans = p_small(diamondsLeft, k * 2, Y);
//                        ans = 0.0;
//                        for (int right=0; right <= k * 2; ++right) {
//                            int left = diamondsLeft - right;
//                            if (left >= 0 && left <= k * 2) {
////                                printf("--> %d %d %d %d = %lf\n", left, right, k * 2, Y, p_small(left, right, k * 2, Y));
//                                ans += p_small(left, right, k * 2, Y);
//                            }
//                        }
                    }
                }
                break;
            }
        }
        assert(ans >= 0.0 && ans <= 1.0);
        printf("Case #%d: %.9lf\n", T++, ans);
    }
	
	return 0;
}
