#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define ll long long
using namespace std;

#define N 111111

int main() {
    freopen("B-large.in" , "r" , stdin) ;
    freopen("B-large.out" , "w" , stdout) ;
    int T ; cin >> T ;
    int ca = 0 ;
    while(T -- ) {
        double c , f , x ;
        cin >> c >> f >> x ;
        double t = 0 ;
        double now = 0 ;
        double add = 2 ;
        if(c >= x) printf("Case #%d: %.7f\n" ,++ ca , x / 2) ;
        else {
            while(now < x) {
                //
                double t1 = (x - now) / add ;
                double t2 = (c - now) / add + x / (add + f) ;
                if(t1 > t2) {
                    t += (c - now) / add ;
                    add = add + f ;
                }
                else {
                    t += t1 ;
                    break ;
                }
            }
            printf("Case #%d: %.7f\n",++ ca ,  t) ;
        }
    }
    return 0 ;
}
