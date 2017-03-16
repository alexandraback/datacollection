#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>

#define PI 3.14159265358979323846
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int z=1;z<=T;z++){
		unsigned long long r,t;
		cin >> r >> t;

		long long L = 0;
		long long R = 710000000ll;

		while(L<R){
			long long M = (L+R+1)/2;

			if(((long double)2*r*M + (long double)M*(1+2*(M-1)))<=t){
				L = M;
			} else {
				R = M-1;
			}
		}
		cout<<"Case #"<<z<<": "<<L<<endl;
	}
}