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

		unsigned long long L = 0;
		unsigned long long R = 2000000000ll;

		while(L<R){
			unsigned long long M = (L+R+1)/2;

			if(((unsigned long long)2*r*M + (unsigned long long)M*(1+2*(M-1)))<=t){
				L = M;
			} else {
				R = M-1;
			}
		}
		cout<<"Case #"<<z<<": "<<L<<endl;
	}
}