#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repf(i, f, l) for(int i = f; i < (int)l; ++i)
#define repit(it, t) for(__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++)

#define endl "\n"

#ifdef ONLINE_JUDGE
#define DEBUG false
#else
#define DEBUG true
#endif

#define pb emplace_back
#define lb lower_bound
#define ul unsigned long
#define ull unsigned long long
#define ll long long
#define INF 1000000007
#define MOD 1000000007
#define fs first
#define sd second
#define DBG0(x) if(DEBUG){ cout << #x << ": " << x << "\t"; }
#define DBG(x) if(DEBUG){DBG0(x); cout << endl;}
#define DBG2(x, y) if(DEBUG){DBG0(x); DBG(y);}
#define DBG3(x, y, z) if(DEBUG){DBG0(x); DBG2(y, z);}
#define DBG4(w, x, y, z) if(DEBUG){DBG0(w); DBG3(x, y, z);}

typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ul> vul;
typedef vector<ull> vull;
typedef vector<bool> vbl;
typedef pair<int, int> pii;

bool valid(vector<pair<int, string>> vs){
    string str;
    for(auto s: vs) str += s.sd;
    set<char> occ;
    char cur = 0;
    for(char c: str){
        if(c != cur){
            occ.insert(cur);
            if(occ.count(c) > 0) return false;
            cur = c;
        }
    }
//    DBG(str);
    return true;
}

void solve(int test_case){
    printf("Case #%d: ", test_case);
    int n;
    cin >> n;
    vector<pair<int, string>> vs(n);
    ll ans = 0;
    rep(i, n){
        string s;
        cin >> s;
        vs[i] = {i, s};
    }
    do{
        if(valid(vs)) ans++;
    }while(next_permutation(vs.begin(), vs.end()));
    cout << ans % MOD << endl;
}
int main(void){
    int t;
    cin >> t;
    rep(i, t) solve(i + 1);
    return 0;
}
