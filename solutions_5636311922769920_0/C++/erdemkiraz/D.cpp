#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "cstring"
#include "string"
#include "vector"
#include "cassert"
#include "queue"
#include "cstdio"
#include "cstdlib"
#include "ctime"
#include "cmath"
#include "bitset"

using namespace std;

typedef long long ll;
typedef pair < int, int > ii;

int h[1000000];

void generate(int n, int c) {
    for(int i = 1; i < (1 << n); i++) {
        vector < int > v;
        for(int x = 0; x < n; x++)
            v.push_back((i >> x) & 1);
        vector < int > start = v;
        for(int mul = 1; mul < c; mul++) {
            vector < int > nv;
            for(auto x : v) {
                if(x == 0) {
                    for(auto tmp : start)
                        nv.push_back(tmp);
                }
                else {
                    for(int i = 0; i < n; i++)
                        nv.push_back(1);
                }
            }
            v = nv;
        }
        bool f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;
        for(int it = 1; it <= v.size(); it++) {
            if(v[it - 1] == 1) {
                printf("%d ", it);
                h[it]++;
                if(it == 1) f1 = 1;
                if(it == 2) f2 = 1;
                if(it == 3) f3 = 1;
                if(it == 4) f4 = 1;
                if(it == 5) f5 = 1;
                if(it == 7) f6 = 1;
            }
        }
        assert(f4 or f6);
        puts("");
    }
    for(int i = 0; i < 1000000; i++) {
        if(h[i] == (1 << n) - 1) {
            puts("OLDU AQ");
            printf("i = %d\n", i);
            return;
        }
    }
}

void solve() {
    
    int k, c;
    
    scanf("%d %d %d", &k, &c, &c
          );
    
    for(int i = 1; i <= k; i++)
        printf("%d ", i);
    
    puts("");
    
}

int main() {
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}