#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

#define FOR(i,a,b)	for(int i=(a); i<(b); ++i)
#define REP(iter,v) for(typeof((v).begin()) iter = (v).begin(); iter != (v).end(); ++iter)
#define MP make_pair
#define PB push_back
#define SZ size()
#define iss istringstream 

#define SORT(x) sort(x.begin(), x.end())
#define ALL(x) x.begin(), x.end()
#define UNIQUE(x) x.erase(unique(x.begin(),x.end()),x.end()) 
#define dbg(x) cerr << #x << " -> '" << (x) << "'\t"
#define dbge(x) cerr << #x << " -> '" << (x) << "'\n"

typedef long long ll, int64;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;

ll MODS[] = {100000007, 100000931};
int64 INF = 1000*1000*1001;

VVI adj;

bool bfs(int st)    {
    bool vis[1024];
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(st);
    vis[st] = true;
    while(! q.empty()) {
        int v = q.front();
        q.pop();
        FOR (i, 0, adj[v].SZ)   {
            int w = adj[v][i];
            if (vis[w]) return true;
            q.push(w);
            vis[w] = true;
        }
    }
    return false;
}

int main(void)	{
	int T;
    int n;
	cin >> T;
	FOR (nc, 1, T+1)	{
        cin >> n;
        // memset(ed, 0, sizeof ed);
        adj = VVI(n);
        FOR (i, 0, n)   {
            int deg;
            cin >> deg;
            FOR (j, 0, deg) {
                int v;
                cin >> v;
                adj[v-1].PB(i);
            }
        }
        
    
        bool ans = false;
        FOR (i, 0, n)   if (!ans) {
            ans = ans || bfs(i);
        }
        
		cout << "Case #" << nc << ": " << (ans ? "Yes" : "No") << endl;
	}
	
	
}
