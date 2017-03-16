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
int T;
int A[1123];

int main() {
    cin >> T;
    cout << "Case #1:" << endl;

    int r, n, m, k;
    cin >> r >> n >> m >> k;

    rep(i, r) {
        rep(j, k) cin >> A[j];
        int flag = 0;
        for(int a = 2 ; !flag && a <= m; a++) 
            for(int b = a ; !flag && b <= m; b++) 
                for(int c = b ; !flag && c <= m; c++)  {
                    int ok = 0;
                    int x[] = {1, a ,b , c, a * b, a * c, b * c, a * b * c};
                    rep(l, k) rep(w, 8) if(A[l] == x[w]) {ok ++; break; }
                    if(ok == k) {
                        cout << a << b << c;
                        flag = 1;
                    }
                }
        if(!flag) rep(i, k) cout << 1; cout << endl; 
    }

    return 0;
}
