#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pr;
typedef pair<ll,ll> prl;

// #define double long double

#define REP(i, n) for (int i = 0; i < n; ++i)

using namespace std;

double C, F, X;

void solve(int t) {
    int k = 0;
    int res = -1;
    double delta = 1000;
    double time = 0;
    
    double last =  X;
    int n = 0 ;
    while (true) {
        last = X / (2 + n * F);
        
        delta = last - (C / (2 + n * F) + X / (2 + (n+1) * F));
        if (delta < 0)
            break;
        n++;
    }
    
    time = 0;
    for (int i = 0; i < n; ++i) {
        time += C / (2 + i*F) ;    
    }
    time += X / (2 + n * F);
    
    printf("Case #%d: %.8lf\n", t + 1, time);
   
}


    
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
 
    int T;
    scanf("%d", &T);
    
    
    for (int t = 0 ; t < T; ++t) {
        scanf("%lf %lf %lf", &C, &F, &X);
        
        solve(t);
        
    }
    
    return 0;
}

