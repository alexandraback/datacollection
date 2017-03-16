#define TASK B

#define _USE_MATH_DEFINES

#define INF (int)(1e9)
#define EPS 1e-9

#define int64 long long
#define uint64 unsigned long long
#define var auto
#define mp make_pair

#define W first
#define H second

#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <sstream>
#include <cstdlib>
#include <stack>
#include <list>
#include <ctime>
#include <cstring>

#define i64 long long


using namespace std;

class B {
    void solve(int test) {
        int D;
        scanf("%d", &D);
        priority_queue<int> source;
        for (int i = 0; i < D; i++) {
            int x;
            scanf("%d", &x);
            source.push(x);
        }
        int answer = 10000;
        for (int y = 1; y <= 1000; y++) {
            auto Q = source;
            
            int x = 0;
            while (Q.top() > y) {
                int mx = Q.top();
                Q.pop();
                Q.push(y);
                Q.push(mx - y);
                x++;
            }
            
            answer = min(answer, x + y);
        }
        printf("Case #%d: %d\n", test, answer);
    }
public:
    B() {
        int T;
        scanf("%d", &T);
        for (int i = 0; i < T; i++) {
            solve(i + 1);
        }
    }
};

int main(int argc, const char * argv[]) {
#ifdef MISTMAC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    new TASK();
    return 0;
}