#define TASK D

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

class D {
    void solve(int test) {
        
        int X, R, C;
        scanf("%d%d%d", &X, &R, &C);
        
        if (R > C) {
            swap(R, C);
        }
        
        if (X >= 7 || (R * C) % X != 0) {
            printf("Case #%d: RICHARD\n", test);
            return;
        }
        for (int a = 1; a <= X; a++) {
            for (int b = 1; b <= X; b++) {
                if (a + b - 1 != X) continue;
            
                if (a > R && b > R) {
                    printf("Case #%d: RICHARD\n", test);
                    return;
                }
                if (a > R && a > C) {
                    printf("Case #%d: RICHARD\n", test);
                    return;
                }
                if (b > R && b > C) {
                    printf("Case #%d: RICHARD\n", test);
                    return;
                }
            }
        }
        
        if (X == 6 && (R == 3 || C == 3)) {
            printf("Case #%d: RICHARD\n", test);
            return;
        }
        
        if (X == 4 && R == 2 && C == 4) {
            printf("Case #%d: RICHARD\n", test);
            return;
        }
        
        printf("Case #%d: GABRIEL\n", test);
    }
public:
    D() {
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