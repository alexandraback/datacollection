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

int n;
long long A;
long long a[111];

int go(long long x, int i){
    if(i == n) return 0;
    if(x > a[i]) return go(x + a[i], i + 1);
    else {
        int ret = 0;
        if(x == 1) return n - i;
        while(x <= a[i]) {
            x += x - 1; 
            ret ++;
        }
        return min(n - i, ret + go(x + a[i], i + 1));
    }
}

int run() {
    cin >> A >> n;
    rep(i, n) cin >> a[i];
    sort(a, a + n);
    return go(A, 0);
}

int main() {
    int t;
    cin >> t;
    rep(i, t) 
        printf("Case #%d: %d\n", i + 1, run());
    return 0;
}
