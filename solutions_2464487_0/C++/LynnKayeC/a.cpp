#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

long double getNum(long double r, long double t)
{
    long double delta = (2 * r - 1) * (2 * r - 1) + 8 * t;
    long double ans = floor((-(2 * r - 1) + sqrt(delta)) / 4);
    return floor(ans);
}

int main()
{
    FILE * fd = fopen("input", "r");
    int casenum = 0;
    long double r;
    long double t;

    fscanf(fd, "%d ", &casenum);
    for (int test = 1; test <= casenum; ++test) {
        fscanf(fd, "%Lf %Lf ", &r, &t);
        fprintf(stdout, "Case #%d: %.0Lf\n", test, getNum(r, t)); 
    }
    return 0;
}

