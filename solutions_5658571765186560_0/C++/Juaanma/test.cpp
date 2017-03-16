#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int nc;
    cin >> nc;

    forn(caso, nc) {
        int x, r, c;
        cin >> x >> r >> c;

        bool res=false;
        if ((r*c)%x!=0) res=true;
        if (x>max(r, c)) res=true;
        if ((x+1)/2>min(r, c)) res=true;
        
        cout << "Case #" << caso+1 << ": " << (res?"RICHARD":"GABRIEL") << endl;
    }

    return 0;
}
