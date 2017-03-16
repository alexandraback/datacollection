#include <bits/stdc++.h>
#define  each(v,c)  for(typeof((c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define  sync(x)    ios_base::sync_with_stdio(x)
#define  pb         push_back
#define  mp         make_pair
#define  sz(a)      ((int)(a.size()))
#define  all(a)     (a).begin(), (a).end()
#define  fi         first
#define  se         second

using namespace std;

#define debug(a,n)    cerr << "["; for(int i = 0; i < n; ++i) cerr << a[i] << " ";cerr << "\b]\n";
#define dbg(args...)  {debug1,args; cerr<<endl;}
#define pause()       cin.get();cin.get();

struct debugger {
    template<typename T> debugger& operator , (const T& v) {
        cerr<<v<<" "; return *this;
    }
} debug1;

template <typename T1, typename T2>
inline ostream& operator << (ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
inline ostream &operator << (ostream & os,const vector<T>& v) {
    bool first = true; os << "[";
    for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if(!first) os << ", ";
        os << *ii; first = false;
    }
    return os << "]";
}

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;

const int NN = 112;

string words, dest;
int K,L,S;

int fail[NN];
int nxt[NN][NN];

void build(){
    int k = 0;
    for(int i = 1; i <= L; ++i){
        while(k > 0 and dest[i] != dest[k])
            k = fail[k-1];
        fail[i] = (k += (dest[i] == dest[k]));
    }
}

int compute(int cur,int idx){
    while(cur > 0 and words[idx] != dest[cur])
        cur = fail[cur-1];
    cur += (words[idx] == dest[cur]);
    return cur;
}


int dp1[NN][NN];
bool vis1[NN][NN];

int f(int x,int match){
    if (x == S) 
        return (match == L);
    
    if (vis1[x][match])
        return dp1[x][match];
    vis1[x][match] = true;

    int ans = 0;
    for(int i = 0; i < K; ++i){
        int nw = nxt[match][i];
        ans = max(ans,f(x+1,nw));
    }

    ans += (match == L);
    dp1[x][match] = ans;
    return ans;
}

double dp[NN][NN];
bool vis[NN][NN];

double func(int x,int match){
    if (x == S){
        if (match == L) return 1.0;
        return 0.0;
    }   
    
    if (vis[x][match]) return dp[x][match];
    vis[x][match] = true;

    double ans = 0.0;
    if (match == L) ans += 1.0;
    
    double prob = 1.0/(double)K;
    for(int i = 0; i < K; ++i){
        int nw = nxt[match][i];
        ans = ans + prob*func(x+1,nw);
    }

    dp[x][match] = ans;
    return ans;
}

void solve(int tc){
    cin >> K >> L >> S;
    cin >> words >> dest;
    
    dest.push_back('$');

    build();
    for(int i = 0; i <= L; ++i){
        for(int k = 0; k < K; ++k){
            nxt[i][k] = compute(i,k);
        }
    }

    memset(vis1,false,sizeof(vis1));
    memset(vis,false,sizeof(vis));

    int banana = f(0,0);
    double res = func(0,0);

    double ans = (double)banana - res;
    cout << "Case #" << tc << ": " << setprecision(6) << fixed << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; ++i)
        solve(i);
    return 0;    
}
