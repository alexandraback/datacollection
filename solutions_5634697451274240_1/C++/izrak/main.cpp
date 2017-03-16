#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int T; scanf("%d", &T);
    FO(Z,0,T) {
        string s; cin >> s;
        int r = s.back() == '-';
        FO(i,1,sz(s)) r += s[i] != s[i-1];
        printf("Case #%d: %d\n", Z+1, r);
    }
}

