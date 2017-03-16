#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		int N,Ncorr;
		cin >> N;

		double s[200], snet=0, snetcorr=0;
		double f[200];
		bool neg[200];
		for(int i=0; i<200; i++){
			s[i]=0;
			f[i]=0;
			neg[i]=false;
		}
		for(int n=0; n<N; n++){
			cin >> s[n];
			snet += s[n];
		}
		Ncorr = N; snetcorr = snet;
		for(int n=0; n<N; n++){
			double temp = (2*snet/N-s[n])/snet*100.0;
			if(temp<0){
				neg[n]=true;
				Ncorr--;
				snetcorr-=s[n];
			}
		}
		double fnet=0;
		for(int n=0; n<N; n++){
			if(neg[n])
				f[n] = 0;
			else{
				if(snetcorr == 0)
					f[n] = 100.0/Ncorr;
				else
					f[n] = ((snetcorr+snet)/Ncorr-s[n])/snet*100.0;
			}
			fnet+=f[n];
		}

		cout << "Case #" << t+1 << ":";
//		printf(" %3.6f", snetcorr);
		for(int n=0;n<N;n++){
			printf(" %3.6f", f[n]);
		}
//		printf(" %3.6f", fnet);
		cout << endl;
	}

	return 0;
}
