#include<iostream>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;
using ll = long long;

void solve() {
	ll b, m;
	scanf("%lld%lld", &b, &m);
	if (m > (1LL << (b-2))) {
		printf("IMPOSSIBLE");
		return;
	}
	printf("POSSIBLE\n");
	int last = (m == (1LL << (b-2)));
	if (last) m--;
	printf("0");
	for (int i = 1; i < b-1; i++)
		printf(((m >> (b-2-i)) & 1) ? "1" : "0");
	printf(last ? "1" : "0");
	for (int i = 1; i < b; i++) {
		printf("\n");
		for (int j = 0; j <= i; j++)
			printf("0");
		for (int j = i+1; j < b; j++)
			printf("1");
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	srand(1);

	int tnumber = 0;
	cin >> tnumber;
	for (int tcase = 1; tcase <= tnumber; tcase++) {
		cout << "Case #" << tcase << ": ";
		solve();
		cout << endl;
	}
	
#ifdef LOCAL
	cerr << "time : " << (double)clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}