#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cstring>

using namespace std;

vector<int> scores;
int n;
int x;

bool isEnough(int i, double t) {
    double scoreI = scores[i] + x * t;
    double fracToDistrib = x * (1 - t);

    for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (scores[j] < scoreI) {
            fracToDistrib -= (scoreI - scores[j]);
        }
    }

    return fracToDistrib < 0;
}

int main() {
    int nCases;
    scanf("%d", &nCases);
    for (int iCase = 1; iCase <= nCases; iCase++) {
        x = 0;
        scanf("%d", &n);
        scores.clear();
        scores.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &scores[i]);
            x += scores[i];
        }
        assert(x > 0);
        printf("Case #%i:", iCase);
        for (int i = 0; i < n; i++) {
            double minT = 0, maxT = 1;
            while (maxT - minT >= 5e-8) {
                double t = (minT + maxT) * 0.5;
                if (isEnough(i, t)) {
                    maxT = t;
                } else {
                    minT = t;
                }
            }
            printf(" %.8f", minT * 100);
        }
        printf("\n");
    }
    return 0;
}
