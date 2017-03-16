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
	int T,N,S,P,Ti,maxi;
	cin >> T;
	for(int caso=1;caso<=T;++caso){
		maxi=0;
		cin >> N  >> S >> P;
		for(int i=0;i<N;++i){
			cin >> Ti;
			if(Ti<2){
				if(Ti>=P)maxi++;
				continue;
			}
			int aux=Ti/3;
			if(!(Ti%3)){
				if(aux>=P){
					maxi++;
				}else{
					if(S&&aux+1>=P){
						S--;
						maxi++;
					}
				}
			}
			if(Ti%3==1){
				if(aux+1>=P){
					maxi++;
				}
			}
			if(Ti%3==2){
				if(aux+1>=P){
					maxi++;
				}else{
					if(S&&aux+2>=P){
						S--;
						maxi++;
					}
				}
			}		
		}
		cout << "Case #" << caso << ": " << maxi << endl;
	}
	return 0;
}
