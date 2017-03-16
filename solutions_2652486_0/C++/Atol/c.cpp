#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

#define FOR(A, B) for(int A = 0; A < (B); A++)

int R, N, M, K;
vector< vector<int> > all;
vector<int> vaux;

void gera(int last, int qtd, int m) {
	if(qtd == 0) {
		all.push_back(vaux);
		return;
	}
	for(int i = last; i <= m; i++) {
		vaux.push_back(i);
		gera(last, qtd-1, m);
		vaux.pop_back();
	}
}

int ok(vector<int> & choice, vector<int> & mults) {
	int n = (int) choice.size();
	set<int> poss;
	FOR(i, (1<<n)) {
		int m = 1;
		for(int j = 0; j < n; j++) {
			if(i & (1<<j)) {
				m *= choice[j];
			}
		}
		poss.insert(m);
	}
	for(int i = 0; i < (int) mults.size(); i++) {
		if (!poss.count(mults[i])) return 0;
	}
	return 1;
}

void go(vector<int> mults) {
	random_shuffle(all.begin(), all.end());
	for(int i = 0; i < (int) all.size(); i++) {
		if(ok(all[i], mults)) {
			for(int j = 0; j < (int) all[i].size(); j++) {
				cout << all[i][j];
			}
			cout << endl; 
			return;
		}
	}
	for(int i = 0; i < N; i++) {
		cout << rand() % (M-1) + 1;
	}
	cout << endl;
}

void solve() {
	cin >> R >> N >> M >> K;
	all.clear(); vaux.clear();
	gera(2, N, M);

	cout << endl;

	FOR(t, R) {
		vector<int> ent;
		FOR(j, K) {
			int aux;
			cin >> aux;
			ent.push_back(aux);
		}
		go(ent);
	}
	
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
