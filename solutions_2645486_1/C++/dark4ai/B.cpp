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

llong E, R, N;
llong v[10100];


int main() {
#ifdef DEBUG
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
#endif
    int T;
    cin >> T;
    for(int test = 1; test <= T; ++test) {
        cin >> E >> R >> N;
        llong sum = 0;
        llong mx = -1;
        for(int i = 0; i < N; ++i) {
            cin >> v[i];
            sum += v[i];
            mx = max(mx, v[i]);
        }
        llong ans = (sum - mx) * R + mx * E;
        cout << "Case #" << test << ": " <<  ans << endl;
    }
    return 0;
}