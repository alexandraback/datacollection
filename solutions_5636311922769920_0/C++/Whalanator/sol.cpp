#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll T,K,C,S;

int main() {
	cin >> T;
	for (int cas=1;cas<=T;cas++) {
		cin >> K >> C >> S;
		printf("Case #%d:",cas);
		if (S*C<K) {
			cout << " IMPOSSIBLE" << endl;
		}
		else {
			ll num=0;
			for (int i=0;i<K;i++) {
				num*=K;
				num+=i;
				if ((i+1)%C==0 || i+1==K) {
					cout << ' ' << num+1;
					num=0;
				}
			}
			cout << endl;
		}
	}
}

