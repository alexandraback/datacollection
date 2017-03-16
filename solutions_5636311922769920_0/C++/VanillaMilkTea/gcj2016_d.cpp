#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
	int T,nocase;
	int K,C,S;

	int i;
	unsigned long long b1,b2,t;
	//unsigned long long arr[100];

	cin >> T;  // read t. cin knows that t is an int, so it reads it as such.
	for (nocase = 1; nocase <= T; ++nocase) {
		cout << "Case #" << nocase << ":";

		cin >> K >> C >> S;
		//cout << "(K,C,S): (" << K << ", " << C << ", " << S << ")" << endl;
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

	return 0;
}