#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int num[20000];
int N;

int run()
{
    int res = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", num + i);
    }
    sort(num, num + N);
    int min_res = num[N - 1];
    for(int diff = num[N - 1] - 1; diff > 1; --diff) {
        int res = diff;
        for(int i = N - 1; i >= 0 && num[i] > diff && res < min_res; --i) {
            res += num[i] / diff + (num[i] % diff == 0 ? -1 : 0);
        }
        min_res = min(min_res, res);
    }

    printf("%d\n", min_res);
    return 0;
}


int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        run();
    }

    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

