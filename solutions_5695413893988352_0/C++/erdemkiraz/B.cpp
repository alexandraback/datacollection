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

int n;
char a[10], b[10];

bool fit(char a[10], int x) {
    vector < int > v;
    while(x) {
        v.push_back(x % 10);
        x /= 10;
    }
    while(v.size() < n)
        v.push_back(0);
    reverse(v.begin(), v.end());
    for(int i = 0; i < n; i++)
        if(a[i] != '?' and v[i] != a[i] - '0')
            return 0;
    return 1;
}

void put(int x) {
    vector < int > v;
    while(x) {
        v.push_back(x % 10);
        x /= 10;
    }
    while(v.size() < n)
        v.push_back(0);
    reverse(v.begin(), v.end());
    for(auto x : v)
        printf("%d", x);
}

void solve() {
    scanf(" %s %s", a, b);
    n = strlen(a);
    vector < int > v1, v2;
    for(int i = 0; i < 1000; i++) {
        if(fit(a, i))
            v1.push_back(i);
        if(fit(b, i))
            v2.push_back(i);
    }
    assert(v1.size());
    assert(v2.size());
    int ans = -1, xx = 0, yy = 0;
    for(auto x : v1) {
        for(auto y : v2) {
            int d = abs(x - y);
            bool flag = 0;
            flag |= ans == -1;
            flag |= d < ans;
            flag |= d == ans and x < xx;
            flag |= d == ans and x == xx and y < yy;
            if(flag) {
                ans = d;
                xx = x;
                yy = y;
            }
        }
    }
    put(xx);
    putchar(' ');
    put(yy);
    puts("");
}

int main () {
    
    freopen("B-small-attempt1.in.txt", "r", stdin);
    freopen("small.txt", "w", stdout);
    
    int n;
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    
    return 0;
    
}