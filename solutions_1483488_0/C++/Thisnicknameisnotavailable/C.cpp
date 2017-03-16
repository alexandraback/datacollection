#include <iostream>
#include <cstdio>
#include <fstream>
#include <bitset>
using namespace std;
/*
	#define cin fin
	#define cout fout
	ifstream fin("B-large.in");
	ofstream fout("B.out");
*/

	char s[20], t[20];

int digit(int n) {
	int c = 0;
	while (n) n /= 10, c++;
	return c;
}

int main() {
	int cn = 1;
	int cs; cin >> cs;
	while (cs--) {
		int A, B;
		cin >> A >> B;

		int N = digit(A);
		sprintf(t, "%c%d%c", '%', N, 'd');
		
		
//		bitset<2000001> visit;
		int ans = 0, n, m;
		for (n=A; n<=B; ++n) {
//			if (visit[n]) continue;
			sprintf(s, "%d%d", n, n);

			for (int i=1; i<N; ++i) {
				sscanf(s+i, t, &m);
				if (n == m) break;
				if (m <= B && n < m) {
					ans++;
//					visit.set(m);
				}
			}
		}
		cout << "Case #" << cn++ << ": " << ans << endl;
	}
//	system("pause");
	return 0;
}
