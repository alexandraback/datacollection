#include <bits/stdc++.h>

using namespace std;

#define sd(x) scanf("%d", &x)
#define boost ios_base::sync_with_stdio(false);
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define f first
#define s second

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 1000000007;
const int inf = 50000000;
const int maxn = 100010;

string arr[maxn][2];

#define MAX 100001
#define NIL 0
#define INF (1<<28)

vector< int > G[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

map<string, int> fw, sw;
map<string, int> :: iterator it;

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	int cn = 1, t, i, j, siz, ans;
	scanf("%d", &t);
	while(t--){
		fw.clear();
		sw.clear();
		memset(match, 0, sizeof(match));
		memset(dist, 0, sizeof(dist));
		for(i=0; i<MAX; i++)
			G[i].clear();
		scanf("%d", &siz);
		ans = 0;
		for(i=0; i<siz; i++){
			cin >> arr[i][0] >> arr[i][1];
			fw[arr[i][0]] = 1;
			sw[arr[i][1]] = 1;
		}
		j = 1;
		for(it=fw.begin(); it!=fw.end(); ++it)
			it->s = j++;
		n = j-1;
		for(it=sw.begin(); it!=sw.end(); ++it)
			it->s = j++;
		m = j-1-n;
		for(i=0; i<siz; i++)
			G[fw[arr[i][0]]].pb(sw[arr[i][1]]);
		int mat = hopcroft_karp();
		//cout << mat << " " << n << " " << m << " " << siz << "\n"; 
		ans = siz-(n+m-mat);
		printf("Case #%d: %d\n", cn++, ans);
	}
	return 0;
}
