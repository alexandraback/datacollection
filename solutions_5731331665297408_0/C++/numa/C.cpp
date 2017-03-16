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

vector<vector<int>> edge;
vector<int> visited;
vector<int> used;
vector<string> zip;
int n, m;

bool valid(vector<int> vs){
    stack<int> stk;
    vector<int> visited(n, 0);

    int id = 0;
    stk.push(vs[id++]);
    while(id < n && !stk.empty()){
        int cur = stk.top();
        bool cond = false;
        for(int son: edge[cur]){
            if(son == vs[id]){
                visited[son]++;
                id++;
                stk.push(son);
                cond++;
                break;
            }
        }
        if(!cond) stk.pop();
    }
    return (id == n);
}

void solver(int tttt){
    cin >> n >> m;
    zip = vector<string>(n);
    edge = vector<vint>(n);
    rep(i, n) cin >> zip[i];
    rep(i, m){
        int x, y;
        cin >> x >> y;
        x--; y--;
        DBG3(n, x, y);
        edge[x].pb(y);
        edge[y].pb(x);
    }
    vector<int> pm;
    rep(i, n) pm.pb(i);
    string str(5 * n, '9') ;
    do{
        if(valid(pm)){
            string cr = "";
            for(int a: pm) cr += zip[a];
            if(cr < str) str = cr;
        }
    }while(next_permutation(pm.begin(), pm.end()));
    printf("Case #%d: %s\n", tttt, str.c_str());
}

int main(void){
    int t;
    cin >> t;
    rep(i, t) solver(i + 1);
    return 0;
}
