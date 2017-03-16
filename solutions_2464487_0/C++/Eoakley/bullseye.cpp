#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
		
int main() {
	int T;
	cin >> T;
	int C=1;
	while(T-- > 0) {
		
		int r, t;
		
		cin >> r >> t;
		
		int resp = 1;
			
		int raio = r+1;
		
		t = t - raio*raio + r*r;
		
		do {
			
			r+=2;
			raio+=2;		

			int aux = raio*raio - r*r;

			if(aux <= t) {
				resp++;
				t = t - aux;
			}
			else break;
		
		} while(1);
		
		cout << "Case #"<<C++<<": "<<resp<<endl;
	}

	return 0;
}

