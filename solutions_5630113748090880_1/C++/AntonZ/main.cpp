#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cstdio>
#include <ctime>
#include <map>

using namespace std;

int h[3000];

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; test++) {
        for (int i = 0; i < 3000; i++) h[i] = 0;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 2*n*n-n; i++) {
            int buf;
            scanf("%d", &buf);
            h[buf]++;
        }

        vector<int> lost;
        lost.reserve(n);
        for (int i = 1; i <= 3000; i++) {
            if (h[i]%2 == 1) lost.push_back(i);
        }

        std::sort(lost.begin(), lost.end());
        printf("Case #%d:", test);
        for (int i = 0; i < n; i++) printf(" %d", lost[i]);
        cout << endl;
    }

    return 0;
}

