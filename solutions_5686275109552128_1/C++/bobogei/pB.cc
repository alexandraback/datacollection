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

const int MX = 1020;
int T;
int N;
int P[MX];
int MaxP;

void printAns(int t, int ans) {
    cout << "Case #" << t << ": " << ans << endl;
}
int main() {
    cin >> T;
    for(int _t=1; _t<=T; _t++) {
        cin >> N;
        MaxP = 0;
        for(int i=0; i<N; i++) {
            cin >> P[i];
            MaxP = max(MaxP, P[i]);
        }
        if (MaxP == 0) {
            printAns(_t, 0);
            continue;
        }
        int ans = MaxP;
        for(int i=1; i<=MaxP; i++) {
            int a = i;
            for(int j=0; j<N; j++) {
                if(P[j]) a += (P[j] - 1) / i;
            }
            ans = min(ans, a);
        }
        printAns(_t, ans);
    }
	return 0;
}

