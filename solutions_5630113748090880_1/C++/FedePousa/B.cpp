#define Federico using
#define Javier namespace
#define Pousa std;
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>


Federico Javier Pousa

int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

int main(){
	int T;
	cin >> T;
	for(int caso=1; caso<=T; ++caso){
		int N;
		cin >> N;
		int lines[105][55];
		int aux[105][55];
		for(int i=0; i<2*N-1; ++i){
			for(int j=0; j<N; ++j){
				cin >> lines[i][j];
				aux[i][j] = lines[i][j];
			}
		}
		int falta;
		int minimoquerompe;
		for(int i=0;; ++i){
			if(i>=N){
				cout << "Se rompio todo" << endl;
				exit(-1);
			}
			int minimo = 100000;
			int cantAp = 0;
			for(int j=0; j<2*N-1; ++j){
				if(aux[j][i]==minimo){
					cantAp++;
				}
				if(aux[j][i]<minimo){
					minimo = aux[j][i];
					cantAp = 1;
				}
			}
			if(cantAp==1){
				falta = i;
				minimoquerompe = minimo;
				break;
			}
			for(int j=0; j<2*N-1; ++j){
				if(minimo==aux[j][i]){
					for(int k=0; k<N; ++k){
						aux[j][k] = 3000;
					}
					
				}
			}
		}
		int bla[3000] = {0};
		for(int j=0; j<2*N-1; ++j){
			bla[lines[j][falta]]++;
			if(lines[j][falta]==minimoquerompe){
				for(int k=0; k<N; ++k){
					bla[lines[j][k]]--;
				}
				bla[minimoquerompe]++;
			}
		}
		cout << "Case #" << caso << ":";
		for(int i=0; i<3000; ++i){
			while(bla[i]){
				cout << " " << i;
				bla[i]--;
			}
		}
		cout << endl; 
	}
	return 0;
}
