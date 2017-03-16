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

void solve(int id) {
    printf("Case #%d: ", id);
    
    int A, B;
    scanf("%d %d", &A, &B);
    
    vector <double> p(A);
    for (int i=0; i < A; ++i) {
        scanf("%lf", &p[i]);
    }
    
    double best = min(2 + B, A + B + 1);
    double acc = 1.0;
    
    for (int i=0; i < A; ++i) {
        acc *= p[i];
        int keys = (A - i - 1) + (B - i - 1) + 1;
        double now = acc * keys + (1 - acc) * (keys + B + 1);
        best = min(best, now);
//        printf("%lf ", now);
    }
//    puts("");
    printf("%.9lf\n", best);
}

int main() {
    int t, T = 1;
    
    scanf("%d ", &t);
    while (t--) {
        solve(T++);
    }
    
    return 0;
}
