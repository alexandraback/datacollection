#include <cstdlib>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end

using namespace std;

bool iseven(int n) {
	if (n % 2 == 0) {
		return true;
	} else {
		return false;
	}
}

int exist(int *a, int b, int N) {
	int i;
	for (i = 0; i < N; i++) {
		if (a[i] == b) {
			return i;
		}
	}
	return -1;

}

int main() {
	int test;
	cin >> test;
	int n;
	for (n = 0; n < test; n++) {
		cout<<"Case #"<<(n + 1)<<":";
		int N;
		cin >> N;
		int t;
		t = 2 * N - 1;
		int **g = (int**) malloc(t * sizeof(int*));
		int i;
		for (i = 0; i < t; i++) {
			int* tmp = (int*) malloc(N * sizeof(int));
			g[i] = tmp;
		}

		int * list = (int *) malloc(N * N * sizeof (int));
		int * count = (int *) malloc(N * N * sizeof (int));
		int k = 0;

		for (i = 0; i < t; i++) {
			int j = 0;
			for (j = 0; j < N; j++) {
				int x;
				cin >> x;
				if (exist(list, x, N*N) != -1) {
					count[exist(list, x, N*N)] = count[exist(list, x, N * N)] + 1;
				} else {
					list[k] = x;
					//cout<<x<<endl;
					count[k] = 1;
					k++;
				}
			}
		}

		int * out = (int *) malloc(N * sizeof (int));
		k = 0;
		for (i = 0; i < N * N; i++) {
			//cout<<count[i]<<endl;
			if (! (iseven(count[i]))) {
				//cout<<i<<endl;
				out[k] = list[i];
				k++;
			}
		}

		for (i = 0; i < N; i++) {
			int j = 0;
			for (j = i + 1; j < N; j++) {
				if (out[i] > out[j]) {
					int tmp = out[i];
					out[i] = out[j];
					out[j] = tmp;
				}
			}
		}

		for (i = 0; i < N; i++) {
			cout<<" "<<out[i];
		}
		cout<<endl;


	}





}