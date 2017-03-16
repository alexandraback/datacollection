#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define RREP(i,s,e) for (i = s; i >= e; i--)
#define rrep(i,n) RREP(i,n,0)
#define REP(i,s,e) for (i = s; i < e; i++)
#define rep(i,n) REP(i,0,n)
#define INF 100000000

typedef long long ll;

int main() {
    int i, t;
    cin >> t;
    rep (i,t) {
        int j, n, ans;
        int bff[1001] {}, len[1001];
        bool used[1001];
        cin >> n;
        REP (j,1,n+1) {
            cin >> bff[j];
            len[j] = 2;
        }
        ans = 0;
        REP (j,1,n+1) {
            fill(used+1,used+n+1,false);
            int x, cnt;
            x = j;
            cnt = 0;
            while (!used[x]) {
                used[x] = true;
                cnt++;
                x = bff[x];
            }
            if (x == j)
                ans = max(ans,cnt);
            else if (x == bff[bff[x]])
                len[x] = max(len[x],cnt);
        }
        int tmp = 0;
        REP (j,1,n+1) if (j == bff[bff[j]])
            tmp += len[j]+len[bff[j]]-2;
        cout << "Case #" << i+1 << ": ";
        cout << max(tmp/2,ans) << endl;
    }
    return 0;
}

