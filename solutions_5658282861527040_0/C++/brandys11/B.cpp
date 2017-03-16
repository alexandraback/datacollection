#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstdio>

using namespace std;

void solve(int t) {
	cout << "Case #"<< t<<": ";
	int A, B, K, res = 0;
	cin >> A >> B >> K;
	vector<int> ans(K, 0);

	for(int i=0; i < A; i++)
		for(int j= 0; j < B; j++) if((i & j) < K) { ans[i&j]++;  }

	for(int i=0; i < K; i++) res+= ans[i];
	cout << res << endl;
}
int main(void) {
	int T;
	cin >> T;

	for(int t=1;t<=T;t++) solve(t);
}