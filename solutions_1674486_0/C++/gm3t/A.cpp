/*
  Name:
  Author: 3T //mailto:kasparovandme@gmail.com
  Date:
  Description:
  Time Limit:
*/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define EPS 1e-7
#define MAXN 1005
#define MODU 1000000007

#define INP "A-small-attempt0.in"
#define OUT "A-small-attempt0.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a, b, c, m;
int Visit[MAXN];
bool Free[MAXN];

vi adj[MAXN];

void dfs(int p){
    REP(i, adj[p].size()){
        Visit[adj[p][i]]++;
        if(Free[adj[p][i]]){
            Free[adj[p][i]] = false;
            dfs(adj[p][i]);    
        }    
    }    
}

bool ok(int pos){
    memset(Visit, 0, sizeof Visit);
    memset(Free, true, sizeof Free);
    //Visit[pos] = 1;
    dfs(pos);
    //FOR(i, 1, n) cout <<pos <<"   " << Visit[i] << endl;
    FOR(i, 1, n) if(Visit[i] >= 2) return true;
    return false;            
}

bool check(){
    FOR(i, 1, n){
        if(ok(i)) return true;    
    }  
    return false;  
}
    
int main () {
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    scanf("%d", &t);
    FOR(i, 1, t){
        //clear
        scanf("%d", &n);
        FOR(j, 1, n) adj[j].clear();
        FOR(j, 1, n){
            scanf("%d", &m);
            FOR(k, 1, m) {scanf("%d", &a); adj[j].pb(a);}   
        }    
        //FOR(u, 1, n) REP(k, adj[u].size()) cout << u <<  "  "  << k << " " <<adj[u][k] << endl;
        printf("Case #%d: ", i);
        if(check()) printf("Yes\n");
        else printf("No\n");          
    }

    return 0;
}
