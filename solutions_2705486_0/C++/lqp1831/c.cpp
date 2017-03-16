#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rev(i, n) for(int i = (n) - 1; i >= 0; --i)
using namespace std;

void bug() { cout << " " << endl; }
template<class T> void bug(T a) { cout << a << "  "; }
template<class T> void bug(T* a, int n) {rep(i, n) bug(a[i]);}

vector<string> v;
vector<string> vv[12];

char s[11111];
int n;
int f[55];

int check(int i, int j, vector<string> & v) {
    int ret = 1000000;
    rep(k, v.size()) {
        int t = 0, last = -10000;
        rep(l, v[k].size()) 
            if(v[k][l] != s[i + l]) {
                if(l - last < 5) {
                    t = 100000000;
                    break;
                }
                last = l;
                t ++;
            }
        ret = min(ret, t);
    }
    return ret;
}

int run() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    memset(f, 0, sizeof(f));
    f[0] = 0;
    rep(i, n + 1) if(i) {
        f[i] = 1000000000;
        for(int j = max(0, i - 10); j < i; j ++)
            f[i] = min(f[i], f[j] + check(j + 1, i, vv[i - j]));
    }
    return f[n];
}


int main() {
    FILE *fin = fopen("dict.txt", "r");
    char buf[111];
    while(-1 != fscanf(fin, "%s", buf)) v.push_back(buf);
    rep(i, v.size()) vv[v[i].size()].push_back(v[i]);

    int t;
    cin >> t;
    rep(i, t) 
        printf("Case #%d: %d\n", i + 1, run());

    return 0;
}
