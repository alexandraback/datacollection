#include <iostream>

using namespace std;

int p[1000];
int t, d, k;

int result(int l) {
	if (l==0) return 1010101;
	int ret = l;
	for (int i=0;i<d;i++) {
		ret += (p[i]-1)/l;
	}
	return ret;
}

int main() {
	cin >> t;
	for (int i=1;i<=t;i++) {
		cin >> d;
		int parsa = 0;
		int sum = 0;
		for (int j=0;j<d;j++) {
			cin >> k;
			p[j] = k;
			sum += k;
			if (k>parsa) parsa = k;
		}
		int b = sum / parsa;
		for (int a = parsa-2; a > b; a--) {
			int ret = result(a);
			if (ret < parsa) parsa = ret;
		}
		cout << "Case #" << i << ": " << parsa << "\n";
	}
}
