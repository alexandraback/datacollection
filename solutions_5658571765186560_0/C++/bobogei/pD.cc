#include<bits/stdc++.h>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define MC(n,m) memcpy((n),(m),sizeof(n))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define ALL(x) x.begin(),x.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)

int T;

bool solve(int x, int r, int c) {
    if(r*c % x != 0) return false;
    if(r < x && c < x) return false;
    if(c < (x+1)/2) return false;
    if(x <= 3) return true;
    if(x == 4) {
        if(c == 2) return false;
    }
    return true;
}

int main() {
    IOS;
    cin >> T;

    for(int _t=1; _t<=T; _t++) {
        int X, R, C;
        cin >> X >> R >> C;
        if(R < C) swap(R, C);
        cout << "Case #" << _t << ": " << ( \
                solve(X, R, C) ? "GABRIEL" : "RICHARD") << endl;
    }
	return 0;
}

