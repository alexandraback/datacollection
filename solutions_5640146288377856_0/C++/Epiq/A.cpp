#include <bits/stdc++.h>
using namespace std;
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define debug(x) (cerr << #x << " = " << (x) << endl)
template<class I> void debug2(I b, I e) { while (b != e) cerr << *b++ << " "; cerr << endl; }

int solve() {
    int r, c, w;
    cin >> r >> c >> w;
    
    int res = r * c / w;
    
    if (c % w == 0) {
        res += w - 1;
    } else {
        res += w;
    }
    
    return res;
}

int main() {
    //freopen("A.in", "r", stdin);
    
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        printf("Case #%d: ", test);
        cout << solve() << endl;
    }
    
    return 0;
}
