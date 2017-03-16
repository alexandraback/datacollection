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

#define MAXSUM ((100000*30))

typedef long long llong;

using namespace std;


vector<int> v1, v2, st;
int n, sum1, sum2, find0;
void rec(int depth) {
    if(find0) return;
    if(depth == n) {
        if(sum1 == sum2 && v1.size() > 0 && v2.size() > 0) {
            for(int i = 0; i < v1.size() - 1; i++) {
                cout << v1[i] << " ";
            }
            cout << v1.back() << endl;
            for(int i = 0; i < v2.size() - 1; i++) {
                cout << v2[i] << " ";
            }
            cout << v2.back() << endl;
            find0 = 1;
        }
        return;
    }
    rec(depth + 1);
    
    v1.push_back(st[depth]);
    sum1 += st[depth];
    rec(depth + 1);
    sum1 -= st[depth];
    v1.pop_back();
    
    v2.push_back(st[depth]);
    sum2 += st[depth];
    rec(depth + 1);
    sum2 -= st[depth];
    v2.pop_back();
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> n;
        st.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> st[i];
        }
        find0 = 0;
        v1.clear();
        v2.clear();
        sum1 = sum2 = 0;
        cout << "Case #" << t << ":" << endl;
        rec(0);
        if(!find0) {
            cout << "Impossible" << endl;
        }
    }    
    return 0;
}
