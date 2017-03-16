#include <bits/stdc++.h>
#define maxx 100005
#define inf 2000000000
#define mod 1000000007
#define pii pair<int,int>
#define piii pair<pii,pii>
#define pli pair<long long,int>
#define f first
#define s second
#define in(x) scanf("%d",&x)
#define IN(x) scanf("%lld",&x)
#define inch(x) scanf("%s",x)
#define indo(x) scanf("%lf",&x)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int t;
ll k, c, s, idx, pos;
ll pw[103];

int main()
{
    freopen("D-large.in", "r", stdin);
    freopen("d_large_output.txt", "w", stdout);
    cin >> t;
    for(int cases = 1; cases <= t; cases++){
        cin >> k >> c >> s;
        cout << "Case #" << cases << ":";
        if(s < (k + c - 1)/c){
            cout << " IMPOSSIBLE" << endl;
            continue;
        }
        s = (k + c - 1)/c;
        pw[0] = 1LL;
        for(ll i = 1; i <= c; i++)
            pw[i] = pw[i - 1]*k;

        for(ll j = 0; j < s; j++){
            idx = j*c*pw[c - 1];
            for(ll i = 2; i <= c; i++)
                idx = idx + pw[c - i]*min(k - 1, j*c + i - 1);
            idx++;
            cout << " " << idx;
        }
        cout << endl;
    }
    return 0;
}
