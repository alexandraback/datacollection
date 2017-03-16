#include <cstdlib>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

int exist(int *a, int b, int N) {
	int i;
	for (i = 0; i < N; i++) {
		if (a[i] == b) {
			return true;
		}
	}
	return false;

}

int main() {
	int test;
	cin >> test;
	int n;
	for (n = 0; n < test; n++) {
		
		cout<<"Case #"<<(n + 1)<<": ";
		int d;
		cin >> d;

		int * a = (int*) malloc(d * sizeof(int));


		int i;
		for (i = 0; i < d; i++) {
			a[i] = -1;
		}
 		int k = 0;
		for (i = 0; i < d; i++) {
			int x;
			cin >> x;

			if (!exist(a, x, d)) {
				k++;
			}
			//cout<<k<<endl;
			a[i] = x;

		}

		int * b = (int*) malloc(d * sizeof(int));
		int p = 0;
		//cout<<k<<endl;

		for (i = 0; i < d; i++) {

			if (exist(b, i, d)) {

			} else {
				int s = a[i];
				if ((a[s - 1]) == (i + 1)) {
					k--;
					b[p] = s - 1;
					p++;
				}
			}
		}
			cout<<max(3,k)<<endl;


	}



}