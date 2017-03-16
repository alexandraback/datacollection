#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define foreach(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair

double C, F, X;

int main() {
    int caseN;
    scanf("%d", &caseN);
    for (int caseI = 1; caseI <= caseN; caseI++)
    {
        printf("Case #%d: ", caseI);

        scanf("%lf %lf %lf", &C, &F, &X);

        double now = 0;
        double rate = 2;
        double res = 1e100;
        int count = 0;
        for (;;) {
            double tmp = now + X / rate;
            if (++count == 10) {
                break;
            }
            if (tmp < res) {
                res = tmp;
                count = 0;
            }

            now += C / rate;
            rate += F;
        }
        printf("%.7lf\n", res);
    }

    return 0;
}
