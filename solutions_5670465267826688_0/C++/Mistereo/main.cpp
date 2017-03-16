#define TASK C

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

class C {
    int T[4][4] = {
        { 1,  2,  3,  4 },
        { 2, -1,  4, -3 },
        { 3, -4, -1,  2 },
        { 4,  3, -2, -1 }
    };
    int multiply(int a, int b) {
        int sign = a * b < 0 ? -1 : 1;
        return sign * T[abs(a)-1][abs(b)-1];
    }
    int match(char x) {
        if (x == 'i') {
            return 2;
        }
        if (x == 'j') {
            return 3;
        }
        if (x == 'k') {
            return 4;
        }
        return 0;
    }
    int binpow(int a, int n) {
        int result = 1;
        while (n) {
            if (n & 1) {
                result = multiply(result, a);
            }
            a = multiply(a, a);
            n >>= 1;
        }
        return result;
    }
    void solve(int test) {
        int L, X;
        bool I = false;
        bool J = false;
        bool K = false;
        scanf("%d%d", &L, &X);
        int current = 1;
        int x = 1;
        //        char c;
        //        do {
        //            scanf("%c", &c);
        //        } while (isspace(c));
        //
        //
        string S;
        cin >> S;
        
        for (int t = 0; t < X; t++) {
            for (int i = 0; i < L; i++) {
                char c = S[i];
                x = multiply(x, match(c));
                current = multiply(current, match(c));
                if (x == 2 && !I) {
                    I = true;
                    x = 1;
                }
                if (x == 3 && I && !J) {
                    J = true;
                    x = 1;
                }
                if (x == 4 && I && J) K = true;
                
                //                scanf("%c", &c);
            }
        }
        //        current = binpow(current, X);
        if (current == -1 && I && J && K) {
            printf("Case #%d: YES\n", test);
        } else {
            printf("Case #%d: NO\n", test);
        }
    }
public:
    C() {
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