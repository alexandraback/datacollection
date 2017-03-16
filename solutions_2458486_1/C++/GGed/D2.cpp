#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define N 405
using namespace std;

int n, m, x;
int b[N], c[N], cnt[N], d[N][N];
int u[N], key[N], v[N], res[N];
vector<int> a[N];
queue<int> advice;
int _key[N], _cnt[N], _v[N];

int dfs(int x, int t){
	if (u[x]) return 0;
	u[x] = 1;
	FOR(i,0,c[x]){
		int k = d[x][i];
		if (k == t) return 1;
		FOR(j,0,a[k].size()) if (!_v[a[k][j]]){
			if (dfs(a[k][j], t)) return 1;
		}
	}
	return 0;
}

int Solvable(){
	int ok;
	while (!advice.empty()) advice.pop();
	FOR(i,0,400){
		_key[i] = key[i];
		_cnt[i] = cnt[i];
	}
	FOR(i,0,n) _v[i] = v[i];
	FOR(i,0,n){
		ok = 1;
		FOR(j,0,n) if (!_v[j]) ok = 0;
		if (ok) return 1;
		FOR(j,0,n) if (!_v[j] && _key[b[j]]){
			if (_key[b[j]] >= _cnt[b[j]]) ok = 1;
			else{
				CLR(u, 0);
				ok = dfs(j, b[j]);
			}
			if (ok){
				advice.push(j);
				_v[j] = 1;
				_key[b[j]]--;
				_cnt[b[j]]--;
				FOR(k,0,c[j]) _key[d[j][k]]++;
				break;
			}
		}
		if (!ok) return 0;
	}
	return 1;
}

void solve(int tc){
	printf("Case #%d:", tc);
	scanf("%d%d", &m, &n);
	CLR(key, 0);
	FOR(i,0,400) a[i].clear(), cnt[i] = 0;
	FOR(i,0,m) scanf("%d", &x), ++key[x-1];
	FOR(i,0,n){
		scanf("%d%d", &b[i], &c[i]), --b[i];
		FOR(j,0,c[i]) scanf("%d", &d[i][j]), d[i][j]--;
		a[b[i]].push_back(i);
		++cnt[b[i]];
		v[i] = 0;
	}

	if (!Solvable()) puts(" IMPOSSIBLE");
	else{
	    FOR(i,0,n){
			int ok = 0;
			FOR(j,0,n) if (!v[j] && key[b[j]]){
				key[b[j]]--;
				cnt[b[j]]--;
				FOR(k,0,c[j]) key[d[j][k]]++;
				v[j] = 1;
				if ((!advice.empty() && advice.front() == j)){
					advice.pop();
					ok = 1;
					printf(" %d", j + 1);
					break;
				}
				if (Solvable()){
					ok = 1;
					printf(" %d", j + 1);
					break;
				}
				key[b[j]]++;
				cnt[b[j]]++;
				FOR(k,0,c[j]) key[d[j][k]]--;
				v[j] = 0;
			}
			if (!ok) puts("Wrong Answer");
		}
		puts("");
	}
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
