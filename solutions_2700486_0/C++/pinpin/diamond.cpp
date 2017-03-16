#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int calc(int A, int v[], int N)
{
    int i;
    int ret;

    if (A == 1)
        return 10000;

    ret = 0;
    i = 0;
    for(i=0;i<N;i++) {
        while (A <= v[i]) {
            ret++;
            A = 2*A-1;
        }
        A += v[i];
    }
    return ret;
}

long long nCm(long long n, long long m)
{
    long long ret;
    long long i;

    ret = 1;
    for(i=0;i<m;i++) {
        ret *= (n-i);
    }
    for(i=0;i<m;i++) {
        ret /= (i+1);
    }

    return ret;
}

long long mypow(long long n, long long m)
{
    long long ret;
    long long i;

    ret = 1;
    for(i=0;i<m;i++) {
        ret *= n;
    }

    return ret;
}

long long calc_enough(int XY)
{
    int sum, tmp;

    if (XY == 0)
        return 1;

    sum = 1;
    tmp = 1;
    while (XY) {
        tmp += 4;
        sum += tmp;
        XY -= 2;
    }

    return sum;
}

int
main(void)
{
    int T;
    int i, j;
    int N, X, Y, XY, tmp;
    double ret;

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> N >> X >> Y;

        XY = abs(X)+abs(Y);

        if (XY > 20) {
            ret = 0.0;
        } else if (X == 0) {
            if (N >= calc_enough(XY)) {
                ret = 1.0;
            } else {
                ret = 0.0;
            }
        } else {
            if (N >= calc_enough(XY)) {
                ret = 1.0;
            } else if (N < (calc_enough(XY-2)+Y+1)) {
                ret = 0.0;
            } else {
                tmp = N - calc_enough(XY-2);
                if (tmp > XY) {
                    if ((tmp-XY) >= (Y+1)) {
                        ret = 1.0;
                    } else {
                        // cout << "here, " << tmp << endl;
                        long long t;
                        t = 0;
                        for(j=max(Y+1,tmp-XY);j<=XY;j++) {
                            t += nCm(tmp,j);
                        }
                        ret = t/(double)mypow(2,tmp);
                    }
                } else {
                     // cout << "here2, " << tmp << endl;
                    long long t;
                    t = 0;
                    for(j=Y+1;j<=tmp;j++) {
                        t += nCm(tmp,j);
                    }
                    ret = t/(double)mypow(2,tmp);
                }
            }
        }

        printf("Case #%d: %.10f\n", i, ret);
    }
    
    return 0;
}
