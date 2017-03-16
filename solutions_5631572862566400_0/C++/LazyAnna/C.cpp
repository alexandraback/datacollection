#include <iostream>
//#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int a[5000];
int c[5000];
bool b[5000];
bool bb[5000];
int n;

int doit(int k, int s) {
	if (s == k) return 0;
	if (bb[k]) {return 0;}
	bb[s] = true;
	int ans = 1;
	while (!bb[a[k]]) {
		++ans;
		bb[a[k]] = true;
		k = a[k];
	}
	if (a[k] == s) {
		return ans;
	} else {
		return 0;
	}
}

int main() {
	int tests;
    int ans;

	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> n;
		ans = 0;

		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <=n; ++j) {
				b[j] = false;
			}
			int count = 1;
			int count1 = 1;
			int count2 = 1;
			int count22 = 0;
			int s = a[i];
			b[i] = true;

			int pre = i;
			while (!b[s]) {
				b[s] = true;
				if (a[s] == i) {
					count1 = count + 1;
				}
				if (a[s] == pre) {
					count22 = 0;
					count2 = count + 1;
					for (int k = 1; k <=n; ++k) {
						for (int kk = 1; kk <=n; ++kk) {
							bb[kk] = b[kk];
						}
						//cout << k << s;
						count22 = max(count22, doit(k, s));

						//cout << s << endl;
					}
					
					count2 += count22;
					//cout << count22 << count2 << s << endl;
				}
				pre = s;
				s = a[s];
				++count;
			}
			if (count2 > ans) {ans = count2;}
			if (count1 > ans) {ans = count1;}
			//cout << ans << i << endl;
		}
		cout << "Case #" << t << ": " << ans << endl;
		//cout << a[5];
	}
	// sort(a, a + d);
	return 0;
}