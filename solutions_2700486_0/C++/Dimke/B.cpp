#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <ctime>
#include <assert.h>
using namespace std;

#define PI 3.141592653589793
#define INF 2123456789
#define NUL 0.0000001

#define for_each(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define SZ size()
#define CS c_str()
#define PB push_back
#define MP make_pair
#define INS insert
#define EMP empty()
#define CLR clear()
#define LEN length()
#define MS(x) memset(x, 0, sizeof(x))
#define MS1(x) memset(x, -1, sizeof(x))

typedef long long LL;
typedef unsigned long long ULL;

double c[22][22];

int main(){
    freopen("B-small-attempt3.in", "r", stdin);
    freopen("B-small-attempt3.out", "w", stdout);

    for (int i = 0; i <= 20; i++){
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    int t; scanf("%d", &t);
    for (int test = 1; test <= t; test++){
        int n, x, y; scanf("%d%d%d", &n, &x, &y);
        x = abs(x);
        int t = 1, level = 0;
        double sol;
        while (true){
            if (t >= n){
                if (level > (x + y) / 2){
                    sol = 1; break;
                }
                if (level < (x + y) / 2){
                    sol = 0; break;
                }
                if (t == n){
                    sol = 1; break;
                }
                if (x == 0){
                    sol = 0; break;
                }
                double good = 0, total = 0;
                for (int i = 0; i <= n; i++)
                    if (i <= t / 2 && n - i <= t / 2){
                        total += c[n][i];
                        //printf("n = %d i = %d c[][] = %lf\n", n, i, c[n][i]);
                        if (i >= y + 1) good += c[n][i];
                    }
                //printf("n = %d t = %d good = %lf total = %lf\n", n, t, good, total);
                sol = good / total;
                break;
            }
            n -= t;
            t += 4; level++;
        }
        printf("Case #%d: %lf\n", test, sol);
    }
    return 0;
}
