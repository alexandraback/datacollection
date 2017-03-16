#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repf(i, f, l) for(int i = f; i < (int)l; ++i)

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

#define ALL(c) (c).begin(),(c).end()

#define DBG0(x)    {if(DEBUG){ cout << #x << ": " << x << "\t"; }}
#define DBG(x)     {if(DEBUG){DBG0(x); cout << endl;}}
#define DBG2(x, y) {if(DEBUG){DBG0(x); DBG(y);}}
#define DBG3(x, y, z) {if(DEBUG){DBG0(x); DBG2(y, z);}}
#define DBG4(w, x, y, z) {if(DEBUG){DBG0(w); DBG3(x, y, z);}}

template <class T>
ostream& operator<<(ostream& os, vector<T> xs){ for(T x: xs) os << x << ' '; return os; }
template <class S, class T>
ostream& operator<<(ostream& os, pair<S,T> st){ os << "(" << st.first << "," << st.second <<")"; return os; }

typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ul> vul;
typedef vector<ull> vull;
typedef vector<bool> vbl;
typedef pair<int, int> pii;

long long rev(long long x){
    ll ret = 0;
    while(x){
        ret *= 10;
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main(void){
    int T;
    cin >> T;
    repf(xx, 1, T + 1){
        ll x;
        cin >> x;
        queue<pair<ll, int>> que;
        que.push({1, 1});
        set<int> vst;
        int ans = 0;
        while(true){
            pair<ll, int> cur = que.front(); que.pop();
            if(cur.fs == x){
                ans = cur.sd;
                break;
            }
            if(vst.count(cur.fs)) continue;
            vst.insert(cur.fs);
            que.push({rev(cur.fs), cur.sd + 1});
            que.push({cur.fs+1, cur.sd + 1});
        }
        cout << "Case #" << xx << ": " << ans << endl;
    }
    return 0;
}
