#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <memory.h>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int powerOfTwo(long long p) {
    long long current = 2;
    int result = 1;
    while(current < p) {
        current *= 2;
        result++;
    }
    if (current == p)
        return result;
    else
        return -1;
}

long long GCD(long long a, long long b) {
    return b==0 ? a : GCD(b, a % b);
}

int main()
{
    // freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int TestNum;
    cin >> TestNum;
    for(int test = 1; test <= TestNum; test++) {
        printf("Case #%d: ",test);
        long long P, Q;
        cin >> P >> Q;
        long long g = GCD(P, Q);
        P /= g;
        Q /= g;
        int power = powerOfTwo(Q);
        if (power != -1) {
            int result = 1;
            while (P * (long long)2 < Q) {
                result++;
                Q /= 2;
            }
            printf("%d", result);
        } else {
            printf("impossible");
        }
        printf("\n");
    }
    return 0;
}

