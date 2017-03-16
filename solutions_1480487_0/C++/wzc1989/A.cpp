/*
 * Author: code6
 * Created Time:  2012/5/6 0:06:16
 * File Name: A.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-11;

int n;
int s[1000];
double ans[1000];
int total;

bool test(int at, double per)
{
    //printf("at = %d, per = %lf\n", at , per);
    double tar = s[at] + total * per;
    int i;
    double le = 1 - per;
    for (i = 0; i < n; i++) {
        if (i != at) {
            double src = s[i];
            //printf("src = %lf, tar = %lf\n", src ,tar);
            if (src < tar) {
                double need = (tar - src) / total;
                if (need <= le || fabs(le - need) < 1e-8) {
                    le -= need;
                } else {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int t, cas = 0;
    int i, j;
    scanf("%d", &t);
    while (t--) {
        cas ++;
        cin >> n;
        total = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &s[i]);
            total += s[i];
        }
        
        for (i = 0; i < n; i++) {
           double lo, hi, mi;
           lo = 0;
           hi = 1;
           while (lo <= hi && fabs(hi - lo) > 1e-8) {
               mi = (lo + hi) / 2;
               
               if (test(i, mi)) {
                   hi = mi;
               } else {
                   lo = mi;
               }
           }
           ans[i] = mi;
        }
        
        printf("Case #%d: ", cas);
        for (i = 0; i < n; i++) {
            if (i) {
                printf(" ");
            }
            printf("%.8lf", ans[i] * 100);
        }
        printf("\n");
    }
    return 0;
}

