#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main() {
    int ts;
    cin >> ts;
    rep(t,0,ts) {
        int n;
        cin >> n;
        map<int,int> cnt;
        rep(i,0,2*n-1) {
            rep(j,0,n) {
                int x;
                scanf("%d", &x);
                cnt[x]++;
            }
        }
        cout << "Case #" << (t+1) << ": ";
        bool first = true;
        iter(it,cnt) {
            if (it->second % 2 != 0) {
                if (first) first = false;
                else cout << " ";
                cout << it->first;
            }
        }
        cout << endl;
    }
    return 0;
}

