#include <bits/stdc++.h>
using namespace std;
#define GET4(_1,_2,_3,_4,...) _4
#define rep_(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) GET4(__VA_ARGS__,repi,rep_,)(__VA_ARGS__)
#define all(c) begin(c),end(c)
template<class C>inline void uniq(C&c){c.erase(unique(all(c)),end(c));}
template<class T>inline bool chmin(T&a,const T&b){return a>b&&(a=b,1);}
template<class T>inline bool chmax(T&a,const T&b){return a<b&&(a=b,1);}

string s;
int n;

void input()
{
    cin >> s;
    n = s.length();
}

const int N = 1024;
char mx[N];

void solve()
{
    mx[0] = s[0];
    rep(i, 1, n) {
        mx[i] = max(mx[i-1], s[i]);
    }
    string ans;
    for (int i = n-1; i >= 0; --i) {
        if (s[i] == mx[i]) {
            ans.push_back(s[i]);
            s[i] = ' ';
        }
    }
    rep(i, n) if (s[i] != ' ') {
        ans.push_back(s[i]);
    }
    cout << ans << endl;
}

int main()
{
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        input();
        cout << "Case #" << i << ": ";
        solve();
    }
}
