#include <bits/stdc++.h>
#define lli long long int
#define endl '\n'

using namespace std;

typedef long long Dato; // Ajustable.
typedef vector<Dato> Vec;
typedef vector<Vec> Mat;
typedef vector<int> Lista;
typedef pair<int, int> Par;
typedef pair<Dato, Dato> Datos;

const Dato INF = 1LL<<60;

struct Flujo {

    int n;
    Lista padre;
    Mat cap, flujo;
    vector<Dato> dist;
    vector<Lista> aristas;

    Flujo(int N) : dist(N), padre(N), aristas(N),
        cap(N, Vec(N)), flujo(N, Vec(N)), n(N) {}

    void AgregarArista(int u, int v, Dato c) {
        flujo[v][u] += c; // Solo dirigidas!
        cap[u][v] += c, cap[v][u] += c;
        aristas[u].push_back(v);
        aristas[v].push_back(u);
    }

    // Flujo maximo mediante Dinic O(V^2E).

    Dato FlujoBloqueante(int u, int t, Dato f) {
        if (u == t) return f; Dato fluido = 0;
        for (int i = 0; i < aristas[u].size(); ++i) {
            if (fluido == f) break; int v = aristas[u][i];
            if (dist[u] + 1 > dist[v]) continue;
            Dato fv = FlujoBloqueante(v, t,
                min(f - fluido, cap[u][v] - flujo[u][v]));
            flujo[u][v] += fv, fluido += fv;
            flujo[v][u] -= fv;
        }
        return fluido;
    }

    Dato Dinic(int s, int t) {
        Dato flujo_maximo = dist[t] = 0;
        while (dist[t] < INF) {
            fill(dist.begin(), dist.end(), INF);
            queue<int> q; q.push(s); dist[s] = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int i = 0; i < aristas[u].size(); ++i) {
                    int v = aristas[u][i];
                    if (flujo[u][v] == cap[u][v] ||
                        dist[v] <= dist[u] + 1) continue;
                    dist[v] = dist[u] + 1, q.push(v);
                }
            }
            if (dist[t] < INF) flujo_maximo +=
                FlujoBloqueante(s, t, INF);
        }
        return flujo_maximo;
    }
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t,u=1,n;
	lli k;
	cin>>t;
	
	while(t--){
		cin>>n>>k;
		
		Flujo g( n + 2 );
		
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				g.AgregarArista( i , j , 1 );
				g.AgregarArista( j , i , 1 );
			}
				
		g.AgregarArista( n , 0 , k );
		g.AgregarArista( n - 1 , n + 1 , k );
		
		Dato f = g.Dinic( n , n + 1 );
		
		cout<<"Case #"<<u++<<": ";
		if(f==k){
			cout<<"POSSIBLE"<<endl;
			
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
					if(g.flujo[i][j]==g.cap[i][j] && i!=j && i!=n-1) cout<<1;
					else cout<<0;
				cout<<endl;
			}
		}
		else cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}




















