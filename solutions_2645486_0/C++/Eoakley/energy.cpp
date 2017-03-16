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

		int resp = 0;
		
		int regen, max, N;
		
		cin >> max >> regen >> N;
		
		int energy[11], v[11], gain[11], use[11];
		bool u[11];

		for(int i=0;i<N;i++) cin >> v[i];
		
		for(int i=0;i<N;i++) u[i] = false;
		
		
		for(int j=0;j<N;j++) {
			int maxV = -1, id=0;
			for(int i=0;i<N;i++) if(!u[i] && v[i] >= maxV) { maxV = v[i]; id=i; }
			
			int e = max;

			for(int i=0;i<N;i++) {
				if(i==id) {
					bool fun=true;
					int euso=e, einicial = e;
					do {
						use[i] = euso; u[i] = true;
						fun=true;
						e = einicial;
						e -= use[i];
						e += regen;
						if(e > max) e = max;
						for(int k=i+1;k<N;k++) {
							if(u[k] && use[k] > e) { fun=false; break; }
							else if(u[k]) { 
								e -= use[k]; e += regen; if(e > max) e = max; }
							else e+= regen;
						}
						euso--;
					} while(!fun);
				}
				else if(u[i]) { 
				e -= use[i]; e += regen; if(e > max) e = max; }
				else if(!u[i]) { e += regen; if(e > max) e = max; }
			}
			//for(int i2=0;i2<N;i2++) {if(u[i2]) cout << use[i2] << " "; else cout << "x "; }cout<<"id max: "<<id<<endl;
		
		}
		
		for(int i=0;i<N;i++) resp += use[i] * v[i];
		
		cout << "Case #"<<C++<<": "<<resp<<endl;
	}

	return 0;
}

