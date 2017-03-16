#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iostream>

using namespace std;

#define FOR(A, B) for(int A = 0; A < (B); A++)

void solve() {
	unsigned long long R, T;
	cin >> R >> T;
	unsigned long long tot = 0;
	unsigned long long ans = 0;
	unsigned long long at = R;
	while(tot <= T) {
		unsigned long long sum = (at+1)*(at+1) - (at)*(at);
		tot += sum;
		at += 2;
		ans++;
	}
	cout << ans-1 << endl;
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
