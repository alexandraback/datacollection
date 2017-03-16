#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
string s;
int u[1024];
int n;

void read() {
    cin>>s;
    n = (int)s.size();
}

int cando(string a) {
    memset(u, 0, sizeof u);
    int j = 0 ;
    for (int i = n - 1; i >= 0; i--) { 
        if (s[i] == a[j]) {
            u[i] = 1;
            ++ j;
        }
        if (j == (int)a.size()) return 1;
    }
    for (int i = 0; i < n; i++) {
        if ( !u[i]) {
            if (s[i] != a[j]) return 0;
            ++ j;
        }
        if (j == (int)a.size()) return 1;
    }
    return 0;

}

void solve() {
    string ans = "";

    for (int j = 0; j < n; j++) {
        for (char i = 'Z'; i >= 'A'; i--) {
            //printf ("%d %c  cando = %d\n", j, i, cando(ans + i));

            if (cando(ans + i)) {
                ans += i;
                break;
            }
        }
    }

    printf ("%s\n", ans.c_str());
}


int main() {
    int cases;

    scanf("%d", &cases);
    for (int i=1; i<=cases; i++) {
        read();
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

