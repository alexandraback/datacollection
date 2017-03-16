#include <iostream> 
#include <stdlib.h>

using namespace std;

struct c {
	bool isPos;
	char p;
};

c times(c a, c b) {
	c r;
	r.isPos = !(a.isPos ^ b.isPos);
	
	if (a.p == '1') {
		r.p = b.p;
		return r;
	}
	if (b.p == '1') {
		r.p = a.p;
		return r;
	}

	if (a.p == b.p) {
		r.p = '1';
		r.isPos = !r.isPos;
		return r;
	}

	if (a.p == 'i' && b.p == 'j') {
		r.p = 'k';
		return r;
	}
	if (a.p == 'k' && b.p == 'j') {
		r.p = 'i';
		r.isPos = !r.isPos;
		return r;
	}
	if (a.p == 'i' && b.p == 'k') {
		r.p = 'j';
		r.isPos = !r.isPos;
		//cout << "R: " << r.isPos << " " << r.p  << endl;
		return r;
	}
	if (a.p == 'j' && b.p == 'k') {
		r.p = 'i';
		return r;
	}
	if (a.p == 'j' && b.p == 'i') {
		r.p = 'k';
		r.isPos = !r.isPos;
		return r;
	}
	if (a.p == 'k' && b.p == 'i') {
		r.p = 'j';
		return r;
	}
}


int main() {
	int t;
	cin >> t;

	for (int q = 0; q < t; q++) {
		long long l, x;
		cin >> l >> x;
		string str;
		cin >> str;
		long long xCount = x % 4;
		if (xCount + 4 >= x) {
			xCount = x;
		} else {
			xCount += 4;
		}
		c sum;
		sum.isPos = true;
		sum.p = '1';
		long long xi = -1, li = -1;
		for (int i = 0; i < xCount; i++) {
			for (int j = 0; j < l; j++) {
				c t;
				t.isPos = true;
				t.p = str[j];
				sum = times(sum, t);
				//cout << "T: " << t.isPos << " " << t.p << endl;
				//cout << "SUM: " << sum.isPos << " " << sum.p << endl;
				if (xi == -1 && li == -1 && sum.isPos && sum.p == 'i') {
					xi = i;
					li = j;
					//cout << "FOUND! " << xi << " " << li << endl;
				}
			}
		}
		
		bool success = false;
		long long xk = -1, lk = -1;
		if (sum.isPos || sum.p != '1' || (xi == -1 && li == -1)) {
			cout << "Case #" << q + 1 << ": NO\n";			
		} else {
			if (xCount + 4 >= x) {
				xCount = x;
			} else {
				xCount += 4;
			}
			sum.isPos = true;
			sum.p = '1';	
			for (int i = xCount - 1; i >= 0; i--) {
				for (int j = l - 1; j >= 0; j--) {
					c t;
					t.isPos = true;
					t.p = str[j];
					sum = times(t, sum);
					if (xk == -1 && lk == -1 && sum.isPos && sum.p == 'k') {
						xk = i;
						lk = j;
						//cout << "I:" << xi << " " << li << endl;
						//cout << "K:" << xk << " " << lk << endl;
						if (xk > xi || (xk == xi && lk > li )) {
							success = true;
						}
						break;
					}
				}
				if (xk != -1 && lk != -1) {
					break;
				}
			}
			if (success) {
				cout << "Case #" << q + 1 << ": YES\n";
			} else {
				cout << "Case #" << q + 1 << ": NO\n";
			}
		}

		
	}
	return 0;
}