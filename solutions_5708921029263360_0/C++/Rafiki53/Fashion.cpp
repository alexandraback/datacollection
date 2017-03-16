#include<bits/stdc++.h>
#define rep(i,k,n) for(int i= (int) k;i< (int) n;i++)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ft first
#define sd second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
const long long INF = 4e18L + 1;
const int IINF = 2e9 + 1;
const int limit = 1048576;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
//     cin.tie(0);
    int T; cin >> T;
    rep(t, 1, T + 1) {
        cout << "Case #" << t << ": ";
        int J, P, S, K; cin >> J >> P >> S >> K;
        if(K > S) {
            cout << J * P * S << "\n";
            rep(j, 1, J + 1)
                rep(p, 1, P + 1)
                    rep(s, 1, S + 1)
                        cout << j << " " << p << " " << s << "\n";
        } else {
            cout << J * P * K << "\n";
            rep(j, 1, J + 1)
                rep(p, 1, P + 1)
                    rep(k, 1, K + 1)
                        cout << j << " " << p << " " << (j + p + k - 3) % S + 1 << "\n";
        }
    }
    return 0;
}