#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(a) ((int)(a).size())

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int nc;
    cin >> nc;

    forn(c, nc) {
        int n, res=0;
        string s;
        cin >> n >> s;
        vector<int> val(n+1, 0);
        forn(i, si(s)) val[i]=s[i]-'0';
        forn(i, si(s)) {
            int suma=0;
            forn(j, i) suma+=val[j];
            if (suma<i) {
                val[i-1]++;
                res++;
            }
        }
        cout << "Case #" << c+1 << ": " << res << endl;
    }

    return 0;
}
