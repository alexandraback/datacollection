#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 0.000000001;
const double PI = 3.141592653589793;
const long long LLINF = 99999999999999999LL;
const int MAX_N = 1000002;

int D[MAX_N];
queue < int > Q;

inline int getReverse(int x) {
    int ret = 0;

    while(x) {
        ret = ret * 10 + x % 10;
        x /= 10;
    }

    return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif

    memset(D, INF, sizeof(D));
    D[1] = 1;
    Q.push(1);
    while(!Q.empty()) {
        int x = Q.front();
        Q.pop();

        int y = x + 1;
        if(D[x] + 1 < D[y]) {
            D[y] = D[x] + 1;
            Q.push(y);
        }

        y = getReverse(x);
        if(D[x] + 1 < D[y]) {
            D[y] = D[x] + 1;
            Q.push(y);
        }
    }

    int T;
    cin >> T;
    for(int test = 1; test <= T; ++test) {
        int N;

        cin >> N;
        printf("Case #%d: %d\n", test, D[N]);
    }

    return 0;
}
