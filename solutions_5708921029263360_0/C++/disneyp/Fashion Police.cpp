#include <iostream>

using namespace std;
int main() {
	freopen("A.in","r",stdin);
	freopen("A.txt","w",stdout);
	int t, J, P, S, K, cnt, ans, L, JJ, PP, LL;
	cin >> t;
	for(int aa=0;aa<t;aa++) {
		cin >> J >> P >> S >> K;
		printf("Case #%d: ",aa+1);
		L = min(S, K);
		ans = J * P * L;
		cout << ans << endl;
		for(int i=1;i<=J;i++) {
			for(int j=1;j<=P;j++) {
				for(int k=0;k<L;k++) {
					printf("%d %d %d\n", i, j, (i + j + k - 1) % S + 1);
				}
			}
		}
		
	}
}
