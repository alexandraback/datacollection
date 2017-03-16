#include <bits/stdc++.h>
using namespace std;

int t, r, c, w;

int main(void) {
    if (fopen("a-small.in","r")) {
        freopen("a-small.in","r",stdin);
        freopen("a-small.out","w",stdout);
    }
    cin >> t;
    for (int ii=1; ii<=t; ii++) {
        cin >> r >> c >> w;
        if (c % w!=0) cout << "Case #" << ii << ": " << ((c/w)*r+w) << "\n";
        else cout << "Case #" << ii << ": " << ((c/w)*r+w-1) << "\n";
    }
    return 0;
}
