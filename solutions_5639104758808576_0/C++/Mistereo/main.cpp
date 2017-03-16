#define TASK A

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

class A {
    void solve(int test) {
        int SMax;
        scanf("%d", &SMax);
        scanf("%s", str);
        int answer = 0;
        int k = 0;
        for (int i = 0; i <= SMax; i++) {
            if (k < i) {
                answer += (i - k);
                k = i;
            }
            k += (str[i] - '0');
        }
        printf("Case #%d: %d\n", test, answer);
    }
public:
    char str[5000];
    A() {
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