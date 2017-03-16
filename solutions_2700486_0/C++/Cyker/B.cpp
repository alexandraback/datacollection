#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433832795
#define INF 0x7FFFFFFF

int T;

int main(int argc, char **argv)
{
    scanf("%d\n", &T);
    REP(t, T) {
        int n, x, y;
        scanf("%d %d %d\n", &n, &x, &y);
        if (x < 0) x = -x;

        //  Table lookup.
        double res = 0.0;
        if (x == 0 && y == 0) {
            res = 1.0;
        } else if (x == 2 && y == 0) {
            if (n <= 1)
                res = 0.0;
            else {
                n -= 1;
                if (n == 1)
                    res = 0.5;
                else if (n == 2)
                    res = 1.0 - 0.5 * 0.5;
                else
                    res = 1.0;
            }
        } else if (x == 1 && y == 1) {
            if (n <= 1)
                res = 0.0;
            else {
                n -= 1;
                if (n == 1)
                    res = 0.0;
                else if (n == 2)
                    res = 0.5 * 0.5;
                else if (n == 3)
                    res = 0.5;
                else
                    res = 1.0;
            }
        } else if (x == 0 && y == 2) {
            if (n <= 1)
                res = 0.0;
            else {
                n -= 1;
                if (n <= 4)
                    res = 0.0;
                else
                    res = 1.0;
            }
        } else if (x == 4 && y == 0) {
            if (n <= 6)
                res = 0.0;
            else {
                n -= 6;
                if (n == 1)
                    res = 0.5;
                else if (n == 2)
                    res = 1.0 - 0.5 * 0.5;
                else if (n == 3)
                    res = 1.0 - 0.5 * 0.5 * 0.5;
                else if (n == 4)
                    res = 1.0 - 0.5 * 0.5 * 0.5 * 0.5;
                else
                    res = 1.0;
            }
        } else if (x == 3 && y == 1) {
            if (n <= 6)
                res = 0.0;
            else {
                n -= 6;
                if (n == 1)
                    res = 0.0;
                else if (n == 2)
                    res = 0.5 * 0.5;
                else if (n == 3)
                    res = 1.0 - (3.0 + 1.0) / 8.0;
                else if (n == 4)
                    res = 1.0 - (1.0 + 4.0) / 16.0;
                else if (n == 5)
                    res = 1.0 - 1.0 / 32.0;
                else
                    res = 1.0;
            }
        } else if (x == 2 && y == 2) {
            if (n <= 6)
                res = 0.0;
            else {
                n -= 6;
                if (n == 1)
                    res = 0.0;
                else if (n == 2)
                    res = 0.0;
                else if (n == 3)
                    res = 0.5 * 0.5 * 0.5;
                else if (n == 4)
                    res = 5.0 / 16.0;
                else if (n == 5)
                    res = 0.5;
                else if (n == 6)
                    res = 1.0 - 22.0 / 64.0;
                else
                    res = 1.0;
            }
        } else if (x == 1 && y == 3) {
            if (n <= 6)
                res = 0.0;
            else {
                n -= 6;
                if (n <= 3)
                    res = 0.0;
                else if (n == 4)
                    res = 1.0 / 16.0;
                else if (n == 5)
                    res = 6.0 / 32.0;
                else if (n == 6)
                    res = 22.0 / 64.0;
                else if (n == 7)
                    res = 61.0 / 128.0;
                else
                    res = 1.0;
            }
        } else if (x == 0 && y == 4) {
            if (n <= 6)
                res = 0.0;
            else {
                n -= 6;
                if (n <= 8)
                    res = 0.0;
                else
                    res = 1.0;
            }
        } else if (x == 6 && y == 0) {
            if (n <= 15)
                res = 0.0;
            else {
                n -= 15;
                if (n == 1)
                    res = 0.5;
                else if (n == 2)
                    res = 1 - 0.5 * 0.5;
                else if (n == 3)
                    res = 1 - 0.5 * 0.5 * 0.5;
                else if (n == 4)
                    res = 1 - 0.5 * 0.5 * 0.5 * 0.5;
                else if (n == 5)
                    res = 1 - 0.5 * 0.5 * 0.5 * 0.5 * 0.5;
            }
        } else if (x == 5 && y == 1) {
            if (n <= 15)
                res = 0.0;
            else {
                n -= 15;
                if (n == 1)
                    res = 0.0;
                else if (n == 2)
                    res = 0.5 * 0.5;
                else if (n == 3)
                    res = 0.5;
                else if (n == 4)
                    res = 1 - 5.0 / 16.0;
                else if (n == 5)
                    res = 1 - 6.0 / 32.0;
            }
        } else if (x == 4 && y == 2) {
            if (n <= 15)
                res = 0.0;
            else {
                n -= 15;
                if (n == 1)
                    res = 0.0;
                else if (n == 2)
                    res = 0.0;
                else if (n == 3)
                    res = 0.5 * 0.5 * 0.5;
                else if (n == 4)
                    res = 5.0 / 16.0;
                else if (n == 5)
                    res = 0.5;
            }
        } else if (x == 3 && y == 3) {
            if (n <= 15)
                res = 0.0;
            else {
                n -= 15;
                if (n == 1)
                    res = 0.0;
                else if (n == 2)
                    res = 0.0;
                else if (n == 3)
                    res = 0.0;
                else if (n == 4)
                    res = 0.5 * 0.5 * 0.5 * 0.5;
                else if (n == 5)
                    res = 6.0 / 32.0;
            }
        } else if (x == 2 && y == 4) {
            if (n <= 15)
                res = 0.0;
            else {
                n -= 15;
                if (n == 1)
                    res = 0.0;
                else if (n == 2)
                    res = 0.0;
                else if (n == 3)
                    res = 0.0;
                else if (n == 4)
                    res = 0.0;
                else if (n == 5)
                    res = 0.5 * 0.5 * 0.5 * 0.5 * 0.5;
            }
        }

        printf("Case #%d: %lf\n", t + 1, res);
    }

    return 0;
}

