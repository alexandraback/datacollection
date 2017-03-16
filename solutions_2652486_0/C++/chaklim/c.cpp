#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

ll t, c, R, N, M, K, product;
vector<ll> v;
ll a[50];

int main() {
	cin >> t;

	int c = 0;
	while (t--) {
		printf("Case #%d:\n", ++c);

		cin >> R >> N >> M >> K;
		while (R--) {
			v.clear();
			for (int i = 0; i < K; i++) {
				cin >> product;
				v.push_back(product);
			}

			bool p = 0;
			for (int i = 2; i <= M && !p; i++) {
				for (int j = 2; j <= M && !p; j++) {
					for (int k = 2; k <= M && !p; k++) {
						a[0] = 1;
						a[1] = i;
						a[2] = j;
						a[3] = k;
						a[4] = i * j;
						a[5] = i * k;
						a[6] = j * k;
						a[7] = i * j * k;

						bool ok = 1;
						for (int m = 0; m < K && ok; m++) {
							bool ok2 = 0;
							for (int n = 0; n < 8 && !ok2; n++) {
								if (a[n] == v[m])
									ok2 = 1;
							}

							if (!ok2)
								ok = 0;
						}

						if (ok) {
							cout << i << j << k << endl;
							p = 1;
						}
					}
				}
			}
		}
	}	

	return 0;
}
