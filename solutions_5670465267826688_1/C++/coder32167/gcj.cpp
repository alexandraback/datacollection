#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <string.h>
#include <math.h>

using namespace std;

int L;
long long X;

/*
    0   1   2   3   4   5   6   7
    1   i   j   k  -1  -i  -j  -k
1   1   i   j   k  -1  -i  -j  -k
i   i  -1   k  -j  -i   1  -k   j
j   j  -k  -1   i  -j   k   1  -i
k   k   j  -i  -1

*/

int mapp[4][4] = {
    {0, 1, 2, 3},
    {1, 4, 3, 6},
    {2, 7, 4, 1},
    {3, 2, 5, 4}
};

char input[200000];

int mul(int a, int b)
{
    int res = ((a & 4) ^ (b & 4)) ^ mapp[a & 3][b & 3];

    //printf("get_nul %d  %d res %d\n", a, b, res);
    return res;
}

int run()
{
    cin >> L >> X;
    scanf("%s", input);
    
    if(X > 12) {
        X = 12 + X % 4;
    }
    if(X > 12) {
        X -= 4;
    }
    int mapper[256];

    mapper['1'] = 0;
    mapper['i'] = 1;
    mapper['j'] = 2;
    mapper['k'] = 3;

    for(int i = 0; i < L; ++i) {
        input[i] = mapper[input[i]];
    }

    for(int i = 1; i < X; ++i) {
        memcpy(input + L * i, input, L);
    }

    L *= X;

    int idx = 0;
    int pre = input[0];
    for(++idx; pre != 1 && idx < L; ++idx) {
        pre = mul(pre, input[idx]);
    }

    if(idx >= L) {
        return -1;
    }

    //cout << " i :" << idx << endl;

    pre = input[idx];
    for(++idx; pre != 2 && idx < L; ++idx) {
        pre = mul(pre, input[idx]);
    }

    if(idx >= L) {
        return -1;
    }

    //cout << " j :" << idx << endl;

    pre = input[idx];
    for(++idx; idx < L; ++idx) {
        pre = mul(pre, input[idx]);
    }

    if(pre != 3) {
        return -1;
    }
    return 0;
}


int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        int res = run();
        if(res < 0) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

