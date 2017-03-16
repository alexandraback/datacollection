
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#define rep(i,s,n) for( int i = s; i < n; ++i)

#define MAX 256

bool test(int i, double point, double total, double p[], int n){
    total -= point;
    rep(j, 0, n){
        if(j != i){
            if(p[i] + point <= p[j]) continue;
            total -= (p[i] + point -  p[j]);
        }
    }
    if(total > 0) return false;
    return true;
}

int main(){
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int t, n, kase = 0;
    double p[MAX], sum, left, right, mid, l, r, min;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        sum = 0;
        rep(i, 0, n){
            scanf("%lf", &p[i]);
            sum += p[i];
        }
        l = sum / n;
        r = 2 * l;
        min = 1000000;
        rep(i, 0, n){
            left = l;
            right = r;
            while(right - left > 1e-7){
                mid = (left + right) / 2;
                if(test(i, mid, sum, p, n))
                    right = mid;
                else left = mid;
            }
            if(min > p[i] + mid)
                min = p[i] + mid;
//            printf(" %lf", mid);
//            if(min < p[i])
//                printf(" %lf", 0.0);
//            else
//                printf(" %lf", (min - p[i]) * 100 / sum);
        }
        printf("Case #%d:", ++kase);
        rep(i, 0, n){
            if(min < p[i])
                printf(" %lf", 0.0);
            else
                printf(" %lf", (min - p[i]) * 100 / sum);
        }
        printf("\n");
    }
    
    return 0;
}
