#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define MEMSET_INF 127
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

bool vis[1000001];

vi g[1000011];


int bfs(int snode, int target){
	queue<pair<int, int> > q;
	q.push(mp(snode,1));
	vis[snode] = 1;

	while(!q.empty()){
		ii cur = q.front();
		q.pop();

		if(cur.F == target)
			return cur.S;

		for(int i = 0; i < g[cur.F].size(); i++){
			if(!vis[g[cur.F][i]]){
				q.push(mp(g[cur.F][i], cur.S + 1));
				vis[g[cur.F][i]] = 1;
			}
		}
	}

	return -1;
}

int r(int x){
	vi v;
	while(x!=0){
		v.pb(x%10);
		x/=10;
	}
	int total = 0;

	int j = 0;
	while(v[j] == 0){
		j++;
	}

	for(int i = j; i < v.size(); i++){
		total *= 10;
		total += v[i];
	}
	return total;
}


int main(int argc, char const *argv[]){
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		int n;
		cin >> n;

		for(int i = 1; i <= n+1; i++){
			g[i].clear();
		}

		for(int i = 1; i <= n; i++){
			g[i].pb(i+1);
			g[i].pb(r(i));
		}
		memset(vis, 0, sizeof vis);

		cout << "Case #" << t << ": " << bfs(1, n) <<  endl;
	}



    return 0;
}