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

int main() {
    IOS;
    int T;
    cin >> T;

    for(int _t=1; _t<=T; _t++) {
        int N;
        string s;
        cin >> N >> s;
        int t = s[0] - '0', ans = 0;
        for(int i=1; i<=N; i++) {
            int q = s[i] - '0';
            if(q && t < i) ans = max(ans, i - t);
            t += q;
        }
        cout << "Case #" << _t << ": " << ans << endl;
    }
	return 0;
}

