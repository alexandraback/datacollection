#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <memory.h>

using namespace std;

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);

    int T;
    cin >> T;
    for (int z = 0; z < T; z++) {
        double C, F, X, R;
        R = 2.0;
        cin >> C >> F >> X;
        double bestTime = X / R;
        double currentTime = 0;
        double N = max(X / C - 2 / F + 1000.0, 1.0);
        for (int i = 0; i < N; i++) {
            if (bestTime > (currentTime + X / R)) {
                    bestTime = currentTime + X / R;
            }
            currentTime += C / R;
            R += F;
        }



        printf("Case #%d: ", z + 1);
        printf("%0.7lf", bestTime);
        printf("\n");
    }
    return 0;
}

