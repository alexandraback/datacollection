#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;
int main() {
	long long int T;
	long long int A;
	long long int B;
	long long int cnt;
	long long int l;
	long long int n;
	string s;
	string ts;
	bool exists[2000010];
	char counts[2000010];
	long long int counter;
	char *ns;
	ns = (char*) malloc(sizeof(char) * 10);
	cin >> T;
	for (long long int i = 1; i <= T; ++i) {
		cin >> A >> B;
		cnt = 0;
		sprintf(ns, "%lld", A);
		l = strlen(ns);
		long long int mul = pow(10, l - 1);
		memset(exists, 0, sizeof(exists));
		for (n = A; n < B; n++) {
			if (!exists[n]) {
				long long int num = n;
				counter = 0;
				int ncnt = 0;
				for (long long int j = 0; j < l - 1; j++) {
					long long int lli = num % 10 * mul + num / 10;
					//cout << "<" << n << ">" << lli << "-" << (lli > n && lli <= B		&& n >= A) << endl;
					if (lli > n && lli <= B && !exists[lli]) {
						//cnt++;
						ncnt++;
						exists[lli] = true;
					}
					num = lli;
				}
				cnt += (ncnt * (ncnt + 1)) / 2;
				exists[n] = true;
			}
		}
		cout << "Case #" << i << ": " << cnt << endl;
	}
	return 0;
}
