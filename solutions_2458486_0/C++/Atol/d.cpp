#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>

#define FOR(A, B) for(int A = 0; A < (B); A++)

using namespace std;

#define N 256
int ini[N];
int abre[N];
int ja[1<<21];
vector<int> ganha[N];
int n, k;
vector<int> order;

int ok(int conj) {
	if(conj == (1<<n) - 1) {
		return 1;
	}
	if (!ja[conj]) return 0;

	FOR(i, n) {
		int ch = i;
		if (conj & (1<<ch)) continue;
		int need = abre[ch];
		if (ini[need]) {
			ini[need]--;
			FOR(j, (int) ganha[ch].size()) {
				ini[ ganha[ch][j] ]++;
			}
			order.push_back(ch);
			if(ok(conj | (1<<ch))) return 1;
			order.pop_back();
			ini[need]++;
			FOR(j, (int) ganha[ch].size()) {
				ini[ ganha[ch][j] ]--;
			}
		} 
	}
	return ja[conj] = 0;
}

void solve() {
  memset(ini, 0, sizeof(ini));
	memset(ja, -1, sizeof(ja));
	order.clear();
  cin >> k >> n;
  FOR(i, k) {
    int t;
    cin >> t;
    ini[t]++;
  }
  FOR(i, n) {
		int qtd;
		cin >> abre[i] >> qtd;
		ganha[i].clear();
		FOR(k, qtd) {
			int aux;
			cin >> aux;	
			ganha[i].push_back(aux);
		}
	}

	if(ok(0)) {
		FOR(i, n) {
			if(i) printf(" ");
			printf("%d", order[i] + 1);
		}
		printf("\n");
		return;
	}
	printf("IMPOSSIBLE\n");
}

int main() {
  int num_testes;
  scanf("%d", &num_testes);
  for(int t = 1; t <= num_testes; t++) {
    printf("Case #%d: ", t);
    solve();
  }
  return 0;
}
