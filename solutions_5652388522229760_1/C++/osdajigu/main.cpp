#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, double>
#define MAX 1000000 + 10
#define INF 0x7fffffff / 2
#define ll long long
#define MOD 1000000007L
#define PI acos(-1)

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<ii> vii;
typedef vector<double> vd;
typedef vector< vector<int> > vvi;
typedef vector< vector<ll> > vvl;
typedef vector< vector<ii> > vvii;


int solve(int n) {
    if(n == 0) return -1;
    int used = 0, N, k;

    for(k = 1; used != (1 << 10) - 1; k++)
        for(int N = n * k; N; N /= 10)
            used |= 1 << (N % 10);

    return n * (k - 1);
}

int cases;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);/**/

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int ans = solve(n);
        cout << "Case #" << ++cases << ": ";
        if(ans == -1) cout << "INSOMNIA\n";
        else cout << ans << "\n";
    }


}
