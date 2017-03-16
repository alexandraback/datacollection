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
        string s;
        cin >> s;
        int g = 1;
        rep(i,1,size(s)) if (s[i] != s[i-1]) g++;
        if (s.back() == '+') g--;
        cout << "Case #" << (t+1) << ": " << g << endl;
    }
    return 0;
}

