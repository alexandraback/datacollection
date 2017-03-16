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

int main() {
	int T;
    scanf("%d", &T);

    for (int t=1; t <= T; ++t) {
        double C, F, X;
        scanf("%lf %lf %lf", &C, &F, &X);

        double best = X / 2.0;
        double acc = 0.0;
        for (int i=1; true; ++i) {
            double timeToWin = X / (2.0 + (i - 1) * F);
            double timeToBuyFarm = C / (2.0 + (i - 1) * F);
            best = min(best, acc + timeToWin);
            acc += timeToBuyFarm;
            if (acc >= best) {
                break;
            }
        }

        printf("Case #%d: %.7lf\n", t, best);
    }
	
	return 0;
}
