#include <iostream>
#include <cmath>

using namespace std;

bool zxcv() {
	bool omg = true;
	int N, M, x;
	cin >> N >> M;
	int *a = new int[N], *b = new int[M], **c = new int*[N];
	for(int i=0; i<N; i++) {
		a[i] = 0;
	}
	for(int j=0; j<M; j++) {
		b[j] = 0;
	}
	for(int i=0; i<N; i++) {
		c[i] = new int[M];
		for(int j=0; j<M; j++) {
			cin >> x;
			if(x > a[i]) a[i] = x;
			if(x > b[j]) b[j] = x;
			c[i][j] = x;
		}
	}
	/*
	for(int i=0; i<N; i++) {
		cout << "a[" << i << "]: " << a[i] << endl;
	}
	for(int j=0; j<M; j++) {
		cout << "b[" << j << "]: " << b[j] << endl;
	}
	*/
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			int d = min(a[i], b[j]);
			if(d != c[i][j]) {
				omg = false;
				break;
			}
		}
		if(!omg) break;
	}
	delete [] a; delete [] b;
	for(int i=0; i<N; i++) {
		delete [] c[i];
	}
	delete [] c;
	return omg;
}

int main() {
	int T;
	cin >> T;
	for(int i=1; i<=T; i++) {
		cout << "Case #" << i << ": " << (zxcv()?"YES":"NO") << endl;
	}
	return 0;
}