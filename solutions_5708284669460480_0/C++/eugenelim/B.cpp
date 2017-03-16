#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> msi;

int K, L, S;
char k[110], t[110], nxt[110];
vector<msi> vm;
msi::iterator it;

int main() {
	int T, tc=1, i, j;
	double res;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &K, &L, &S);
		scanf(" %s ", k);
		scanf(" %s ", t);
		vm.clear();
		vm.assign(S+1, msi());
		for (i=0; i<K; i++) {
			string curk = "";
			curk += k[i];
			if (vm[1].count(curk) == 0) {
				vm[1][curk] = 0;
			}
			vm[1][curk]++;
		}
		for (i=1; i<S; i++) {
			for (it=vm[i].begin(); it!=vm[i].end(); ++it) {
				string curk = it->first;
				int curv = it->second;
				for (j=0; j<K; j++) {
					memset(nxt, 0, sizeof nxt);
					strcpy(nxt, curk.c_str());
					nxt[i] = k[j];
					if (vm[i+1].count(nxt) == 0) {
						vm[i+1][nxt] = 0;
					}
					vm[i+1][nxt]+=curv;
				}
			}
		}
		int maxct = 0;
		double total = 0;
		double deno = 0;
		for (it=vm[S].begin(); it!=vm[S].end(); ++it) {
			string curk = it->first;
			int curv = it->second;
			int ct = 0;
			for (i=0; i<S; i++) {
				if (i+L > S) break;
				bool add = true;
				for (j=0; j<L; j++) {
					if (curk[i+j] != t[j]) {
						add = false;
						break;
					}
				}
				if (add) ct++;
			}
			maxct = max(maxct, ct);
			total += ct*curv;
			deno += curv;
		}
		res = 1.0*maxct - total/deno;
		printf("Case #%d: %.10lf\n", tc++, res);
	}
	return 0;
}