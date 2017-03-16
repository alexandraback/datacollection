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
        
        int b, m; cin >> b >> m;
        if(m > (1 << (b - 2))) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        cout << "POSSIBLE\n";
        
        cout << "0";
        if(m == (1 << (b - 2))) {
            rep(i, 1, b)
                cout << "1";
            cout << "\n";
        }
        else {
            rep(i, 1, b - 1) {
                if(m & (1 << (b - 2 - i)))
                    cout << "1";
                else
                    cout << "0";
            }
            cout << "0";
            cout << "\n";
        }
        rep(i, 1, b) {
            rep(j, 0, i + 1)
                cout << "0";
            rep(j, i + 1, b)
                cout << "1";
            cout << "\n";
        }
    }
    return 0;
}