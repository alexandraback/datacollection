#include<iostream>
using namespace std;

int main() {
	int T, Tidx;
	cin >> T;
	unsigned long A,exchange, Acurr;
	int N, Nidx,Nidx2;
	int MinOp,Op;
	int X[100];
	for(Tidx = 0; Tidx<T; Tidx++) {
		cin >> A >> N;
		for(Nidx=0; Nidx<N; Nidx++) {
			cin >> X[Nidx];
		}

		for(Nidx=0; Nidx<N; Nidx++) {
			for(Nidx2=Nidx+1; Nidx2<N; Nidx2++) {
				if (X[Nidx]>X[Nidx2]) {
					exchange = X[Nidx];
					X[Nidx] = X[Nidx2];
					X[Nidx2] = exchange; 
				}
			}
		}

		MinOp = N;
		Op = 0;
		Acurr = A;
		if (Acurr >1) {
			for(Nidx=0; Nidx<N; Nidx++) {						
				while(X[Nidx]>=Acurr) {
					Acurr = 2*Acurr-1;
					Op++;
				}
				Acurr += X[Nidx];
				if (N-Nidx-1+Op < MinOp)
					MinOp = N-Nidx-1+Op;
			}
		}
		cout << "Case #" << Tidx+1 << ": ";
		cout << MinOp << endl;
	}
	
	return 0;
}
