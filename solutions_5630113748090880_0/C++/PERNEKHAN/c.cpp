#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define y1 stupid_y1
#define ll long long
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define file ""

const int inf = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);

void solve(){
    int n;
    scanf("%d", &n);
    map < int, int > M;
    for (int i=1;i<=2*n-1;i++){
        for (int j=1;j<=n;j++){
            int x; scanf("%d", &x);
            M[x]++;
        }
    }
    vector < int > ans;
    forit(it, M){
        if (it->s % 2 == 1){
            ans.pb(it->f);
        }
    }
    forit(it, ans){
        cout <<*it<<" ";
    }
    cout <<endl;
}


int main () {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    int T;
    scanf("%d", &T);

    for (int i=1;i<=T;i++){
        printf("Case #%d: ", i);
        solve();
    }


    #ifdef LOCAL
    cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif

    return 0;
}