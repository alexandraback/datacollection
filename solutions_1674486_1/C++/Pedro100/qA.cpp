#include <cstdio>
#include <vector>
#include <queue>
#define N 10000

using namespace std;
typedef long long ll;

vector<int> adj[N];
int in[N];
queue<int> fila;
ll mk[N][30];

int main(){
	int n, m, q;
	int casos;
	scanf("%d",&casos);
	for(int u=1; u<=casos; u++){
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			adj[i].clear(), in[i] = 0;
			for(int j=0; j<20; j++) mk[i][j]=0LL;
		}
		for(int i=1; i<=n; i++){
			scanf("%d",&q);
			int u;
			for(int j=0; j<q; j++){
				scanf("%d",&u);
				adj[i].push_back(u);
				in[u]++;
			}
		}
		
		while(!fila.empty()) fila.pop();
		for(int i=1; i<=n; i++){
			if(in[i] ==0) fila.push(i);
		}
		
		bool tem = false;
		while(!fila.empty() && !tem){
			int v = fila.front();
			mk[v][(v-1)/50] |= 1LL<<(ll)((v-1)%50);
			fila.pop();
			
			for(int i=0; i<adj[v].size(); i++){
				int w = adj[v][i];
				//printf(" >>%d %d\n",v,w);
				for(int j=0; j<20; j++){
					if((mk[v][j] & mk[w][j]) != 0LL)
						tem = true;
					mk[w][j] |= mk[v][j];
				}
				in[w]--;
				if(in[w] == 0) fila.push(w);
			}
		}
		
		if(tem) printf("Case #%d: Yes\n",u);
		else printf("Case #%d: No\n",u);
	}
	
	return 0;
}
