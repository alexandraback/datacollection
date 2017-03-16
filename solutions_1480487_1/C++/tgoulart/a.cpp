#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

#define DEBUG
#ifdef DEBUG
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...) 
#endif

#define EPS 1e-12

void solve(int id) {
    printf("Case #%d:", id);
    
    int n, sum = 0;
    
    scanf("%d", &n);
    
    vector <int> values(n);
    
    for (int i=0; i < n; ++i) {
        scanf("%d", &values[i]);
        sum += values[i];
    }
    
    for (int k=0; k < n; ++k) {
        double from = 0.0, to = 1.0 + EPS;
        
        while (to-from > EPS) {
            double now = (from + to) / 2.0;
            
            double value = values[k] + sum * now;
            double sum_others = 0.0;
            bool good = true;
            
            for (int i=0; i < n; ++i) {
                if (i == k) {
                    continue;
                }
                
                if (values[i]-EPS > value) {
                    continue;
                }
                
                sum_others += (value - values[i]);
            }
            
            if (good && sum_others+EPS > sum * (1.0 - now)) {
                to = now;
            }
            else {
                from = now;
            }
        }
        assert(from <= 1.0);
        printf(" %.9lf", from * 100.0);
    }
    puts("");
}

int main() {
    int t, T = 1;
    
    scanf("%d ", &t);
    while (t--) {
        solve(T++);
    }
    
    return 0;
}
