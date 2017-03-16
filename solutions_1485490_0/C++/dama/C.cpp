#include <stdio.h>
#include <queue>

using namespace std;

long long sol;

void simulate(queue<pair<long long, int> > A, queue<pair<long long, int> > B, long long cur) {
     //printf("cur = %lld\n", cur);
     if (A.empty() || B.empty()) {
        sol = max(cur, sol);
        return;
     }
     if (A.front().second == B.front().second) {
        long long val = min(A.front().first, B.front().first);
        cur += val;
        if (A.front().first == val) {
           A.pop();
        } else {
           A.front().first -= val;
        }
        if (B.front().first == val) {
           B.pop();
        } else {
           B.front().first -= val;
        }
        simulate(A, B, cur);
     } else {
        queue<pair<long long, int> > tempA = A, tempB = B;   
        tempA.pop();
        tempB.pop();
        simulate(tempA, B, cur);
        simulate(A, tempB, cur); 
     }
}


int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    
    int t, n, m;
    scanf("%d", &t);
    
    for (int test = 1; test <= t; ++test) {
        scanf("%d %d", &n, &m);
        queue<pair<long long, int> >A, B;
        for (int i = 1; i <= n; ++i) {
            long long x;
            int y;
            scanf("%lld %d", &x, &y);
            A.push(make_pair(x, y));
        }
        for (int j = 1; j <= m; ++j) {
            long long x;
            int y;
            scanf("%lld %d", &x, &y);
            B.push(make_pair(x, y));
        }
        sol = 0;
        simulate(A, B, 0);
        printf("Case #%d: %lld\n", test, sol);
    }   
    
    return 0;
}
