#include <iostream>
using namespace std;

int sn[31] = {0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10};
int st[31] = {0,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,10,10};
int main() {
	int n ; cin >> n;
	for (int i = 0; i < n; ++i) {
		int N, p, S, ans;
		ans = 0;
		cin >> N >> S >> p;
		for (int j = 0; j < N; ++j) {
			int tmp; cin >> tmp;
			if (sn[tmp] >= p) { ans++; continue;}
			if (st[tmp] < p) continue;
			if (S > 0) {
				ans++;
				S--;
				continue;
			}
		}
		cout << "Case #" << i+1 << ": "<< ans << endl;
	}
}