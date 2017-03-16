#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

double A[1024], B[1024];

void do_case(int cn) {
	int N;
	cin >> N;
	for(int i=0;i<N;i++) cin >> A[i];
	for(int i=0;i<N;i++) cin >> B[i];
	sort(A,A+N);
	sort(B,B+N);
	int r1 = 0;
	for(int i=0, j=0;i<N;i++) {
		if (A[i] > B[j]) {
			r1++;
			j++;
		}
	}
	int r2 = 0;
	vector<int> v(N,1);
	for(int i=N-1;i>=0;i--) {
		int f = 0, p;
		for(int j=0;j<N;j++) if (v[j] && B[j] > A[i]) {
			f = 1;
			p = j;
			break;
		}
		if (f) {
			v[p] = 0;
		} else {
			for(int j=0;j<N;j++) if (v[j]) {
				p = j;
				break;
			}
			v[p] = 0;
			r2++;
		}
	}
	cout << "Case #" << cn << ": " << r1 << " " << r2 << endl;
}

int main() {
	int T;
	cin >> T;
	for(int i=1;i<=T;i++) {
		do_case(i);
	}
	return 0;
}