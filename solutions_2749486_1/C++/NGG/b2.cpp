#include <iostream>
#include <vector>
using namespace std;

#define ABS(x) ((x) < 0 ? -(x) : (x))

int getmin(int k) {
	int n = 0;
	int s = 0;
	for (n = 0;; n++) {
		s += n;
		if (s >= k && ((s-k)%2) == 0) return n;
	}
}

void calcvec(std::vector<bool>& v, int k, int n) {
	for (int i = n; i >= 1; i--) {
		if (i <= k) {
			v[i] = true;
			k -= i;
			if (k == 0) return;
		}
	}
}

int main(void)
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ti++) {
		int x, y;
		cin >> x >> y;
		cout << "Case #" << ti << ": ";
		int a = x+y, b = x-y;
		int na = getmin(ABS(a));
		int nb = getmin(ABS(b));
		int n = max(na, nb);
		std::vector<bool> va(n+1, false), vb(n+1, false);
		calcvec(va, (ABS(a) + n*(n+1)/2)/2, n);
		calcvec(vb, (ABS(b) + n*(n+1)/2)/2, n);
		for (int i = 1; i <= n; i++) {
			bool ba = va[i]^(a < 0);
			bool bb = vb[i]^(b < 0);
			if (ba && bb) cout << "E";
			else if (ba && !bb) cout << "N";
			else if (!ba && bb) cout << "S";
			else cout << "W";
		}
		cout << endl;
	}
	return 0;
}
