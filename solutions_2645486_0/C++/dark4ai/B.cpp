#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>

#define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define printf_debug(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define printf_debug(fmt, args...)
#endif

typedef long long llong;

using namespace std;

int E, R, N;
int v[11];
int maxans = -1234567890;

void rec(int d, int e, int ans) {
    maxans = max(ans, maxans);
    if(d == N) {        
        return;
    }
    for(int i = e; i >= 0; --i) {
        rec(d + 1, min(e - i + R, E), ans + i * v[d]);
    }
}

int main() {
#ifdef DEBUG
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
#endif
    int T;
    cin >> T;
    for(int test = 1; test <= T; ++test) {
        cin >> E >> R >> N;
        maxans = -1234567890;
        for(int i = 0; i < N; ++i) {
            cin >> v[i];
        }
        rec(0, E, 0);
        cout << "Case #" << test << ": " <<  maxans << endl;
    }
    return 0;
}