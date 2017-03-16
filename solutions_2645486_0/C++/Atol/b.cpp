#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iostream>

using namespace std;

#define FOR(A, B) for(int A = 0; A < (B); A++)

#define MAX 20000
#define XX 20
long long E, R, N;
long long v[MAX];
long long pd[MAX][XX];

long long go(int pos, int k) {
	if(pos == N) return 0;
	if(pd[pos][k] != -1) return pd[pos][k];
	long long ans = 0;
	for(int i = 0; i <= k; i++) {
		ans = max(ans, i*v[pos] + go(pos+1, min(k-i+R, E)));
	}
	return pd[pos][k] = ans;
}

void solve() {
	cin >> E >> R >> N;
	FOR(i, N) {
		cin >> v[i];
	}
	memset(pd, -1, sizeof(pd));
	cout << go(0, E) << endl;
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
