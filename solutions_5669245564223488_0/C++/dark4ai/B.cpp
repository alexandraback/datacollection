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

int p[110];

bool is_valid(string s) {
    int n = s.size();
    int used[26];
    memset(used, 0, sizeof(used));
    int prev = -1;
    for(int i = 0; i < n; ++i) {
        int cur = s[i] - 'a';
        if(prev == -1) {
            prev = cur;
        } else if(prev != cur) {
            used[prev] = 1;
            prev = cur;
            if(used[cur]) return false;
        }
    }   
    return true;
}

int main() {
#ifdef DEBUG
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
#endif
    int T;
    scanf("%d\n", &T);
    for(int t = 1; t <= T; ++t) {
        cerr << t << endl;
        int n;
        cin >> n;
        vector<string> s(n);
        for(int i = 0; i < n; ++i) {
            cin >> s[i];
            p[i] = i;
        }
        int ans = 0;
        do {
            string res = "";
            for(int i = 0; i < n; i++) {
                res += s[p[i]];
            }
            ans += (int)is_valid(res);
        } while(next_permutation(p, p + n));
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}