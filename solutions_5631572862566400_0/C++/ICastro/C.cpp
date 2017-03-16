#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF numeric_limits<int>::max()
#define LINF numeric_limits<ll>::max()
#define mp make_pair
#define mt make_tuple
#define getT(T, p) get<p>(T)
#define pb push_back
#define st first
#define nd second
#define contOnes __builtin_popcountl
#define powDI __builtin_powi
#define sz(v) int(v.size())
//cuidado parametro duplicados
#define all(X) (X).begin(), (X).end()
#define logLow(X) (X <= 0 ? 0 : 31 - __builtin_clz(X))
#define logUpper(X) (X <= 1 ? 0 : 32 - __builtin_clz(X-1))
#define pow2(X) ((X)*(X))
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vii;

const double EPS = 1e-8;
//const double PI = atan(1.0)*4;
const double PI = 2*acos(0.0);
inline int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main(void) {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		////cout << "AA" << endl;
		int n;
		cin >> n;
		vi vet(n);
		vvi grafoFull(n);
		vvi invGrafo(n);
		////cout << "AA" << endl;
		for (int i = 0; i < n; ++i) {
			cin >> vet[i];
			vet[i]--;
			grafoFull[i].pb(vet[i]);
			grafoFull[vet[i]].pb(i);
			invGrafo[vet[i]].pb(i);
		}
		////cout << "AA" << endl;

		int nVis = 0;
		int p = 0;
		vi vis(n);
		int g = 1;
		////cout << "AA" << endl;
		while (nVis != n){
			//cout << "p0 " << p << " visp " << vis[p] << endl;
			while (vis[p] != 0) p++;
			//cout << "p1 " << p << " visp " << vis[p] << endl;
			vi pilha;
			pilha.pb(p);
			while (!pilha.empty()){
				int v = pilha.back();
				pilha.pop_back();
				//cout << "v " << v << " visv " << vis[v] << endl;
				if (vis[v] != 0) continue;
				vis[v] = g;
				//cout << "vg " << v << " " << g << endl;
				nVis++;
				for (int i = 0; i < sz(grafoFull[v]); ++i){
					if (vis[grafoFull[v][i]] != 0) continue;
					pilha.pb(grafoFull[v][i]);
				}
			}
			g++;
		}
		////cout << "AA" << endl;
		g--;
		vi aux(g, -1);
		vi auxCont(g, -1);
		int auxContTotal = 0;
		int auxContMax = 0;

		vi rec;
		////cout << "AA" << endl;
		for (int i = 0; i < n; ++i) {
			//cout << vet[i] << " ";
		}
		//cout << endl;
		for (int i = 0; i < n; ++i) {
			if(vet[vet[i]] == i && vet[i] > i) {
				vet.pb(i);
				aux[vis[i] - 1] = i;
				//cout << "rec " << i << endl;
				////cout << "rec " << vet[i] << endl;
				////cout << "rec " << vet[vet[i]] << endl;
			}
		}
		//cout << "AA" << endl;
		vi pos(n, -1);
		for (int i = 0; i < g; ++i){
			if (aux[i] != -1) {
				//cout << "if" << endl;
				pos[aux[i]] = 0;
				pos[vet[aux[i]]] = 0;
				//cout << "aux[i] " << aux[i] << endl;
				//cout << "vet[aux[i]] " << vet[aux[i]] << endl;
				auxCont[i] = 2;
				vi aaa(2);
				aaa[0] = aux[i];
				aaa[1] = vet[aux[i]];
				for(int j = 0; j < 2; ++j){
					int maxPos = 0;
					vi pilha;
					pilha.pb(aaa[j]);
					while (!pilha.empty()){
						int v = pilha.back();
						pilha.pop_back();
						for (int k = 0; k < sz(invGrafo[v]); ++k){
							//cout << "lol " << invGrafo[v][k] << endl;
							if (pos[invGrafo[v][k]] != -1) continue;
							pilha.pb(invGrafo[v][k]);
							pos[invGrafo[v][k]] = pos[v] + 1;
							maxPos = max(maxPos, pos[v] + 1);
						}
					}
					auxCont[i] += maxPos;
					//cout << "maxPos " << maxPos << endl;
				}
				auxContTotal += auxCont[i];
			} else {
				//cout << "else" << endl;
				vi pilha;
				int p = 0;
				//cout << "i "<< i << endl;
				while (vis[p] != i+1) p++;
				pilha.pb(p);
				pos[p] = 0;
				while (!pilha.empty()){
					int v = pilha.back();
					//cout << "V " << v << endl;
					pilha.pop_back();
					if (pos[vet[v]] != -1){
						auxCont[i] = pos[v] - pos[vet[v]] + 1;
					} else {
						pos[vet[v]] = pos[v] + 1;
						pilha.pb(vet[v]);
					}
				}
				auxContMax = max(auxContMax, auxCont[i]);
			}
		}
		//cout << "BB" << endl;

		cout << "Case #" << t+1 << ": " << max(auxContTotal, auxContMax) << endl;
	}

	return 0;
}
