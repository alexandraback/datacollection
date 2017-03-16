#define _CRT_SECURE_NO_WARNINGS
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
//#define endl "\n"
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
#define all(c) (c).begin(), (c).end()
#define loop(i,a,b) for(ll i=a; i<ll(b); i++)
#define rep(i,b) loop(i,0,b)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
template<class T> ostream & operator<<(ostream & os, vector<T> const &);
template<int n, class...T> typename enable_if<(n>=sizeof...(T))>::type _ot(ostream &, tuple<T...> const &){}
template<int n, class...T> typename enable_if<(n< sizeof...(T))>::type _ot(ostream & os, tuple<T...> const & t){ os << (n==0?"":" ") << get<n>(t); _ot<n+1>(os, t); }
template<class...T> ostream & operator<<(ostream & os, tuple<T...> const & t){ _ot<0>(os, t); return os; }
template<class T, class U> ostream & operator<<(ostream & os, pair<T,U> const & p){ return os << "(" << p.first << ", " << p.second << ") "; }
template<class T> ostream & operator<<(ostream & os, vector<T> const & v){ rep(i,v.size()) os << v[i] << (i+1==(int)v.size()?"":" "); return os; }
template<class T> inline bool chmax(T & x, T const & y){ return x<y ? x=y,true : false; }
template<class T> inline bool chmin(T & x, T const & y){ return x>y ? x=y,true : false; }
#ifdef DEBUG
#define dump(...) (cerr<<#__VA_ARGS__<<" = "<<mt(__VA_ARGS__)<<" ["<<__LINE__<<"]"<<endl)
#else
#define dump(...)
#endif
// ll const mod = 1000000007;
// ll const inf = 1LL<<60;

// Small : dijkstra
// Large : greedy

typedef int Weight;
struct Edge {
    int src, dst;
    Weight weight;
    Edge(int src_, int dst_, Weight weight_) :
        src(src_), dst(dst_), weight(weight_) { }
};
bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
        e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

int const inf = 1<<29;

// あり本のダイクストラ法
Weight dijkstra(Graph const & g, int s, int t = inf) {
    typedef tuple<Weight,int> State;
    priority_queue<State> q;
    vector<Weight> dist(g.size(), inf);
    dist[s] = 0;
    q.emplace(0,s);
    while (q.size()) {
        Weight d;
        int v;
        tie(d,v) = q.top(); q.pop();
        d *= -1;
        if(v == t) return d;
        if (dist[v] < d) continue;
        rep(i,g[v].size()){
            const Edge &e = g[v][i];
            if (dist[e.dst] > dist[v] + e.weight) {
                dist[e.dst] = dist[v] + e.weight;
                q.emplace(-dist[e.dst], e.dst);
            }
        }
    }
    return -1;
}

int my_stoi(string & s){
    int res = 0;
    rep(i,s.size()) res = res*10 + s[i]-'0';
    return res;
}

int rev(int x){
    stringstream ss;
    ss << x;
    string s = ss.str();
    reverse(all(s));
    return my_stoi(s);
}

int solve(){
    int N;
    cin >> N;
    Graph g(N*10);
    for(int i=1;i<N;i++){
        int d1 = i+1;
        int d2 = rev(i);
        g[i].eb(i,d1,1);
        g[i].eb(i,d2,1);
    }
    return dijkstra(g,1,N);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    rep(i,T){
        int ans = solve()+1;
        printf("Case #%d: %d\n", (int)i+1,ans);
    }
}
