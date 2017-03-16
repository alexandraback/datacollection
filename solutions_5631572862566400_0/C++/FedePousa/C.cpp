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

int main(){
	int T;
	cin >> T;
	for(int caso=1; caso<=T; ++caso){
		int N;
		cin >> N;
		int bff[1005];
		for(int i=0; i<N; ++i){
			cin >> bff[i];
			bff[i]--;
		}
		vector<int> aux;
		for(int i=0; i<N; ++i){
			aux.push_back(i);
		}
		int maximo = 0;
		do{
			for(int i=1; i<N; ++i){
				bool sirve = true;
				for(int j=0; j<=i; ++j){
					sirve = (aux[(j-1+i+1)%(i+1)]==bff[aux[j]]) || ((aux[(j+1)%(i+1)]==bff[aux[j]]));
					if(!sirve)break;
				}
				if(sirve){
					maximo = max(maximo,i+1);
				}
			}
		}while(next_permutation(aux.begin(),aux.end()));
		
		cout << "Case #" << caso << ": " << maximo << endl;
	}
	
	return 0;
}
