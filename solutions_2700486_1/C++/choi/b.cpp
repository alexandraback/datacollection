#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;


double f(int n,int k) {
	if (k > n-k) {
		k = n-k;
	}
	double ret = 1.0;
	for (int i=1; i<=n-k; i++) {
		ret /= 2.0;
	}
	for (int i=n; i>=n-k+1; i--) {
		ret *= i;
		ret /= 2.0;
	}
	for (int i=k; i>=1; i--) {
		ret /= i;
	}

	return ret;
}


void tst()
{
	int N,X,Y;
	cin >> N;
	cin >> X;
	cin >> Y;

	int z = abs(X)+Y;
	float p;

	int sum_L = (z/2+1)*(z+1);
	int sum_S = z*(z-1)/2;

	if (N >= sum_L) {
		p = 1;
	} else if (N <= sum_S) {
		p =0;
	} else {
		int a = N - sum_S;
		// 1< a < sum_L -sum_S;
		if (a >= z + Y+1) {
			p = 1;
		} else if (Y+1 > a) {
			p = 0;
		} else if (Y+1 == z+1) {
			p = 0;
//		} else if (a <=z) {
		} else {
			if (Y+1 < z/2) {
				p = 1;
				for (int i=Y; i>=0; i--) {
					p -= f(a,i);
				}
			} else {
				p = 0;
				for (int i=Y+1; i<=a; i++) {
					p += f(a,i);
				}
			}
//		} else {
//			p = 1;
//			for (int i=Y; i>=0; i++) {
//				p -= f(a,i);
//			}
		}
	}

	cout << p;
	
	return;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
		cout << "Case #" << i+1 << ": ";
		tst();
		cout << endl;
	}
}



