#include <iostream>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#include <utility>

using namespace std;
//using namespace __gnu_cxx;

typedef long long LL;
typedef double DB;
typedef unsigned int uint;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef istringstream IS;
typedef ostringstream OS;

#define INF (1<<30)
#define INFLL (1LL<<61LL)
#define EPS (1e-9)
#define PB push_back
#define FI first
#define SE second
#define ALL(v) (v).begin(),(v).end()
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))
#define FUP(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
#define FDN(i,a,b) for(int (i)=(a);(i)>=(b);--(i))
#define FORS(i,a) for(int (i)=0;(i)<(int)(a).size();++(i))
#define FORE(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();++i)
#define PRINT(v) for(int (i)=0;(i)<(int)(v).size();(i)++) cerr<<v[i]<<" "; cerr<<endl;

VI tab[2000];
int cnt[2000];
bool ans = false;

void dfs(int v, int p){
    if(cnt[v] == p){
        ans = true;
        return;
    }
    cnt[v] = p;
    FORS(i,tab[v]){
        dfs(tab[v][i], p);
    }
}

void run(int cnum){
    int n;
    cin >> n;
    ans = false;
    REP(i,n){
        tab[i].clear();
        cnt[i] = 0;
    }
    REP(i,n){
        int m;
        cin >> m;
        REP(j,m){
            int k;
            cin >> k;
            tab[k-1].PB(i);
            cnt[i]++;
        }
    }
    REP(i,n){
        if(cnt[i] == 0 && !ans){
            dfs(i,-i-1);
        }
    }
    cout << "Case #" << cnum << ": " << (ans ? "Yes" : "No") << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    int C;
    cin >> C;
    REP(i,C) run(i+1);
    return 0;
}

