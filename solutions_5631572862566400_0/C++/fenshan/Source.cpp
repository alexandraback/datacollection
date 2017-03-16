#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;

#define For(i, a) for (int i = 0; i < a; ++i)
#define FOR(i, v) for (int i = 0; i < v.size(); ++i)
#define sol(i, sol) cout << "Case #" << i+1 << ": " << sol << "\n";

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

struct aaa{
	ii n, m;
};

int main(){
	int n, sol0, sol, a, two, aux;
	bool twoAd;
	cin >> n;
	For (i, n){
		cin >> a; sol0 = 0;
		vector <bool> visited(a, false);
		vector <bool> t(a, false);
		vector<int> v(a);
		vector <aaa> aa;
		For(j, a){
			cin >> v[j];
		}
		int dos=0;
		For(j, a){
			if (v[v[j] - 1] == j + 1 && !t[j]){
				t[j] = t[v[j] - 1] = true;
				dos += 2;
				aa.push_back({ { j, v[j] - 1 }, { 0, 0 } });
			}
		}
		FOR(j, v){
			if (!visited[j]){
				aux = j; sol = 1;
				vector <bool> vis(a, false);
				visited[aux] = vis[aux] = true;
				while (!vis[v[aux]-1]){
					aux = v[aux] - 1;
					vis[aux] = true;
					++sol;
				}
				if (sol > sol0 && v[aux] - 1 == j && !t[aux]){
					sol0 = sol;
					twoAd = false;
				}
				if (t[aux]){
					int xx;
					FOR(z, aa){
						if (aux == aa[z].n.first){
							if (aa[z].m.second < sol - 2) aa[z].m.second = sol - 2;
							xx = aa[z].m.first + aa[z].m.second + 2;
							break;
						}
						if (aux == aa[z].n.second){
							if (aa[z].m.first < sol - 2) aa[z].m.first = sol - 2;
							xx = aa[z].m.first + aa[z].m.second + 2;
							break;
						}
					}
					if (xx > sol0){
						twoAd = true;
						sol0 = xx;
					}
				}				
			}
		}
		if (twoAd){
			sol0 += dos - 2;
		}
		if (sol0 < 0)sol0 = 0;
		sol(i, sol0);
	}
	return 0;
}