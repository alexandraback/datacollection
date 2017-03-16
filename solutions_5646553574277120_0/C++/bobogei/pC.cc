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

typedef long long i64;
int T, C, D, V;
vector<i64> ip;

int main() {
    IOS;
    cin >> T;
    for(int _t=1; _t<=T; _t++) {
        ip.clear();
        cin >> C >> D >> V;
        for(int i=0; i<D; i++) {
            i64 d;
            cin >> d; ip.PB(d);
        }

        sort(ip.begin(), ip.end());

        int ans = 0, id = 0;
        i64 n = 0;
        while(n < V) {
            if(id >= D or ip[id] > n+1) {
                ans ++;
                n += (n+1) * C;
            } else {
                n += ip[id++] * C;
            }
        }
        cout << "Case #" << _t << ": " << ans << endl;
    }
	return 0;
}

