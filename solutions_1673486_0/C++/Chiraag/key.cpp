#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		int A, B;
		cin >> A >> B;
//		cout << A << " " << B << endl;
		double N=B+2;
		double p[100000], n[100000];
		for(int a=0; a<100000; a++){
			p[a]=0;
		}

		for(int a=0; a<A; a++){
			cin >> p[a];
		}

		for(int a=0; a<=A; a++){
			int pass = 1+2*a+(B-A);
			int fail = (a==A)?pass:pass+B+1;
			double ppass = 1;
			for(int i=0;i<(A-a);i++){
				ppass *= p[i];
			}
			double pfail = 1-ppass;
			n[a] = ppass*pass + pfail*fail;
//			cout << "n[" << a << "] = " << n[a] << endl;
		}

		for(int a=0; a<=A; a++){
			N = min(N,n[a]);
		}

		printf("Case #%d: %6.6f\n", (t+1), N);
//		cout << "Case #" << t+1 << ": " << linet << endl;
	}

	return 0;
}
