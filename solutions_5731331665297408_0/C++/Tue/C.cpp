//Written by technolt~h
 
#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>
 
#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))
 
#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()
 
#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define ll long long
using namespace std;
 
const double PI = 2.0 * acos (0.0);
 
typedef long long LL;
typedef pair <int, int> PII;
 
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }
 
#define X first
#define Y second

#define maxn 10

int n,m;
bool a[maxn][maxn];
int parent[maxn];
bool visit[maxn];
string lab[maxn];
string res;

void dfs(int u,int &nvisited) {
    visit[u]=true;
    nvisited++;
    FOR(i,1,n) if(visit[i]==false && parent[i]==u && a[u][i]) dfs(i,nvisited);
}

int root;

bool chk() {

    int nedge=0;
    FOR(i,1,n) {
        if(i!=parent[i])
            nedge++;
    }
    if(nedge!=n-1) return false;
    FOR(i,1,n) {
        int nvisited=0;
        RESET(visit,false);
        dfs(i,nvisited);

        root=i;
        if(nvisited==n) return true;
    }
    return false;
}

string cur;
void find(int u) {
    cur+=lab[u];
    vector<pair<string,int> > list;
    FOR(v,1,n) if(v!=u && parent[v]==u) list.PB(MP(lab[v],v));
    sort(list.begin(),list.end());
    REP(i,list.size()) find(list[i].second);
}

void solve() {
    if(!chk()) return;

    cur="";
    find(root);
    if(res=="" || cur<res) res=cur;
}

void att(int x) {
    if(x>n) {
        solve();
        return;
    }
    FOR(i,1,n) {
        parent[x]=i;
        att(x+1);
    }
}

int main() {
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cin >> n >> m;
        FOR(i,1,n) cin >> lab[i];
        RESET(a,false);
        FOR(i,1,m) {
            int x,y;
            cin >> x >> y;
            a[x][y]=true;
            a[y][x]=true;
        }
        res="";
        cerr << test << endl;
        att(1);
        cout << "Case #" << test << ": " << res << endl;

    }
}