#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int T;
double C, F, X;

double solve() {
    double gall = 2.0;
    double ans = 0.0, cost1, cost2, cost3;
    
    cost1 = (X / gall);
    
    while (true) {
        cost2 = (C / gall);
        cost3 = (X / (gall + F));
        if (cost1 < cost2 + cost3) {
            ans += cost1;
            break;
        } else
            ans += cost2;
        
        cost1 = cost3;
        gall += F;
        
    }
    
    return ans;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> C >> F >> X;
        printf("Case #%d: %.7lf\n", t, solve());
    }
    
    return 0;
}
