#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef int var;

var BEST[1000005];

var rev(var n) {
    var r = 0;

    if(n % 10 == 0)
        return n+1;
    while(n) {
        r = r*10 + n % 10;
        n /= 10;
    }
    return r;
}

var Solve() {
    memset(BEST, 0xf, sizeof(BEST));
    var n;
    cin>>n;

    BEST[0] = 0;

    for(var i=1; i<=n; i++) {
        var r = rev(i);
        //cerr << i << " " << r << "\n";
        BEST[i] = min(BEST[i-1], BEST[r]);
        BEST[i] ++;
    }

    //fo/r(var i=1; i<=n; i++) {
        //cerr << BEST[i]<< " ";
    //}
    //cerr<<endl;

    return BEST[n];
}

int main() {
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);

    var t;
    cin>>t;
    for(var tt=1; tt<=t; tt++) {
        cout<<"Case #"<<tt<<": "<<Solve()<<'\n';
    }
}
