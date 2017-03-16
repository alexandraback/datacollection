// * You barely lifted your hand and Lesser Dog got excited.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int res = 0;
    rep(i,0,s.size() - 1){
        if(s[i]!=s[i+1]) res++;
    }
    if(s[s.size()-1]=='-') res++;
    cout << res;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    rep(i, 0, q) {
        cout << "Case #" << (i + 1) << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
