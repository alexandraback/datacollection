#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <limits.h>
#include <memory.h>
 
using namespace std;
 
#define LL               long long
#define pb               push_back
#define mp               make_pair
typedef vector <int>     vi; 
typedef vector <string>  vs;
typedef pair   <int,int> pii;

LL p, q;
int res;


LL ucln(LL p, LL q) {
    if (q == 0) return p;
    return ucln(q, p%q);
}


void reduce(LL& p, LL& q) {
    LL d = ucln(p, q); 
    p /= d; q /= d;
}

void solve() {
    res = 0;
    while (true) {
        res++;    
        if (p*2 >= q) return;
        
        q /= 2; 
    }
}


int main() {
    int num_test; LL one = 1;

    //
    scanf("%d", &num_test);
    for (int i=1; i<=num_test; i++) {
        scanf("%lld/%lld", &p, &q);
        reduce(p, q);
        //printf("%lld %lld\n", p, q);

        //
        res = -1;
        for (LL j=1; j<=40; j++) {
            if (q == (one<<j)) {
                res = j;
                break;
            }   
        }

        //
        printf("Case #%d: ", i);
        if (res == -1) printf("impossible\n"); else { solve(); printf("%d\n", res); }
    }
    
    //printf("%lld\n", (one<<40));
    //printf("%lld\n", (one<<38));
    //printf("%lld\n", (one<<31));

    //
    return 0;
}
