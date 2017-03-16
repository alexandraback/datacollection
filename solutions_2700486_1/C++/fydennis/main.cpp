#include<iostream>	
#include<math.h>
using namespace std;

double NchoseK(int N, int K);

int main()
{
	int T=0, Tidx;
	int N,X,Y;
	int k,Minner,Mouter,r,s, remain;
	double pr;
	cin >> T;
	for(Tidx = 0; Tidx<T; Tidx++) {
		cin >> N >> X >> Y;
		k = (((X>0)?X:(-X))+Y)/2;
		Minner = k * (2*k-1);
		Mouter = (k+1) * (2*k+1);
		r = 2 * k;
		s = Y + 1;
		if (X==0) {
			if (N>= Mouter)
				pr = 1.0;
			else
				pr = 0.0;
		}
		else if (N>=Minner+r+s)
			pr = 1.0;
		else if (N<Minner+s)
			pr = 0.0;
		else {
			remain = N-Minner;
			pr = 1.0;
			for (int sidx = 0;sidx<s;sidx++) {
				pr = pr-NchoseK(remain,sidx);
			}
			//pr = NchoseK(remain,s);
		}
		cout << "Case #" << Tidx+1 << ": ";
		cout <<  pr << endl;
	}		
	return 0;
}

double NchoseK(int N, int K) {
	double pr = 1;
	int idx;
	for (idx =0;idx<K;idx++) {
		pr = pr*(N-idx)/(K-idx)/2;
	}
	for (idx =K;idx<N;idx++)
		pr = pr/2;
	return pr;
}