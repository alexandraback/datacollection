#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


/*int factor(ll n) {
	for (int c=2;c*c<=n;c++) if (n%c==0) return c;
	return 0;
}*/


	int N,J,T;


int main() {
	cin >> T;
	for (int cas=1;cas<=T;cas++) {
		printf("Case #%d:\n",cas);
		cin >> N >> J;

		long long poss=(ll)1<<(N-1);
		poss++;
		while (J) {
			vector<int> divs;
			for (int base=2;base<=10;base++) {
				bool s=0;
				for (int div=2;div<32000 && !s;div++) {
					int p=1;
					int rem=0;
					for (int c=0;c<N;c++) {
						if (poss&((ll)1<<c))
							rem=(rem+p)%div;
						p*=base;p%=div;
					}
					if (rem==0) {
						s=1;
						divs.push_back(div);
					}
				}
				if (!s) goto tryagain;
			}

			J--;
			for (int c=N-1;c>=0;c--) cout << bool((1ll<<c)&poss);
			for (int c=2;c<=10;c++) cout << ' ' << divs[c-2];
			cout << endl;
tryagain:;
	 poss+=2;
		}
	}
}
