#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

long long cal(long long n, long long r, long long t)
{
    return 2 * n * n + (2 * r - 1) * n - t;
}

long long getNum(long long r, long long t)
{
    long long st = 1;
    long long ed = std::min(std::sqrt(t), t / r + 1.0);
    long long mid = (st + ed) / 2;
    while (st <= ed) {
        mid = (st + ed) / 2;
        if (cal(mid, r, t) > 0) {
            ed = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return ed;
}

int main()
{
    FILE * fd = fopen("input", "r");
    int casenum = 0;
    long long r;
    long long t;

    fscanf(fd, "%d ", &casenum);
    for (int test = 1; test <= casenum; ++test) {
        fscanf(fd, "%lld %lld", &r, &t);
        fprintf(stdout, "Case #%d: %lld\n", test, getNum(r, t)); 
    }
    return 0;
}

