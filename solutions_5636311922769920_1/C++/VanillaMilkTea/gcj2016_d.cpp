#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void nextPos(unsigned long long *ind, int K, unsigned long long pos){
	*ind = (*ind-1)*K + pos + 1;
}

int main(int argc, char* argv[]){
	int T,nocase;
	int K,C,S;

	int i,j,num;
	unsigned long long u,v;
	unsigned long long b1,b2,t;
	unsigned long long arr[100];

	cin >> T;  // read t. cin knows that t is an int, so it reads it as such.
	for (nocase = 1; nocase <= T; ++nocase) {
		cout << "Case #" << nocase << ":";

		cin >> K >> C >> S;
		//cout << "(K,C,S): (" << K << ", " << C << ", " << S << ")" << endl;

		if( S >= K){
			for(i=0,b1=1,b2=1;i<C-1;i++){
				b1 = b1 * K;
				b2 = b2 + b1;
			}
			//cout << "b1: "<< b1 <<" , b2: " << b2 << endl;
			for(i=0;i<S;i++){
				t = i*b2 + 1;
				cout << " " << t;
			}
			cout<< endl;
		}
		else {
			num = (K + C - 1)/C;
			if((C==1)||(num>S)) {
				cout << "IMPOSSIBLE" << endl;
			}
			else {
				//i=1;
				//if(K >= C){
				for(i=1;i*C < K;i++){
					u = (i-1)*C+1; v = 1;
					//printf("%llu %llu\n",u,v);
					for(j=2;j<=C;j++){
						//nextPos(&u,K,v);
						v = v + 1;
						u = (u-1)*K + v;
						//printf("%llu %llu\n",u,v);
					}
					cout << " " << u;
				}
				//printf("\n");
				u = (i-1)*C+1; v = 1;
				//printf("%llu %llu\n",u,v);
				t = K%C; if(t==0) t = C;
				for(j=2;j<=C;j++){
					if(v<t) v = v + 1;
					u = (u-1)*K + v;
					//nextPos(&u,K,v);
					
					//printf("%llu %llu\n",u,v);
				}
				//printf("\n");
				cout << " " << u << endl;
			}
		}
	}

	return 0;
}