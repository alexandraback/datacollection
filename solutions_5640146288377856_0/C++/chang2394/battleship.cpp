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

const int NN = (1 << 20);

int row,col,width;
int dp[NN];
bool vis[NN];

bool valid(int mask){
    int prev = -1, cnt = 0;
    for(int i = 0; i < col; ++i){
        if (mask & (1 << i)){
            int diff = i-prev-1;
            cnt += (diff >= width);
            prev = i;
        }
    }

    int diff = col-prev-1;
    cnt += (diff >= width);
    return (cnt > 0);
}

int eval(int mask){
    int prev = -1, ans = 0;
    for(int i = 0; i < col; ++i){
        if (mask & (1 << i)){
            int diff = i-prev-1;
            ans = max(ans,diff);
            prev = i;
        }
    }
    
    //dbg("at",mask,ans,prev,col);
    ans = max(ans,col-prev-1);
    if (ans == width) return ans;
    return width+1;
}

int f(int mask){
    if (vis[mask]) return dp[mask];
    vis[mask] = true;

    int ans = numeric_limits<int> :: max();
    int add = eval(mask)-1;
    
    //dbg("at",mask,add);
    for(int i = 0; i < col; ++i){
        if (mask & (1 << i)) continue;
        int temp = mask | (1 << i);
        if (valid(temp))
            ans = min(ans,row + f(temp));
        else 
            ans = min(ans, row + add);
    }

    dp[mask] = ans;
    return ans;
}

void solve(int tc){
    cin >> row >> col >> width;
    memset(vis,false,sizeof(vis));
    int ans = f(0);
    cout << "Case #" << tc << ": " << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    for(int i = 1; i <= t; ++i)
        solve(i);
    return 0;    
}
