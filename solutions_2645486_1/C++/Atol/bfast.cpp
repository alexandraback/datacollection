#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

#define FOR(A, B) for(int A = 0; A < (B); A++)

#define MAX 20000
long long E, R, N;
long long v[MAX];
long long need[MAX], have[MAX];
vector< pair<long long, long long> > fila;

void solve() {
	cin >> E >> R >> N;
	fila.clear();
	FOR(i, N) {
		cin >> v[i];
		need[i] = 0;
		have[i] = E;
		fila.push_back( make_pair(-v[i], i) ); 
	}
	sort( fila.begin(), fila.end() );
	long long ans = 0;
	FOR(i, N) {
		int pos = fila[i].second;
		long long val = -fila[i].first;
		ans += max(0ll, (have[pos] - need[pos])) * val;
		long long rr = 0;
		for(int j = pos+1; j < N; j++) {
			rr += R;
			have[j] = min(have[j], rr);
		}
		rr = have[pos];
		for(int j = pos-1; j >= 0; j--) {
			rr -= R;
			need[j] = max(need[j], rr);
		}
	}
	cout << ans << endl;
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
