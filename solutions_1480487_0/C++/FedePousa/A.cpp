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
int T,N,s[205],X,puntos[205];
double res[205];

bool puedo(int i,int med){
	int abajo=0;
	for(int a=0;a<N;++a){
		if(a==i)continue;
		abajo+=max(0,s[i]+med+1-s[a]);
	}
	return abajo>=(X-med);
}

int main(){	
	cin >> T;
	for(int caso=1;caso<=T;++caso){
		X=0.0;
		cin >> N;
		for(int i=0;i<N;++i){
			cin >> s[i];
			X+=s[i];
		}
		
		for(int i=0;i<N;++i){
			int inf=0;
			int sup=X;
			int med;
			if(puedo(i,0)){
				puntos[i]=0;
				continue;
			}
			while(inf+1!=sup){
				//~ cerr << inf << " " << sup << " " << med << endl;
				med=(inf+sup)/2;
				if(puedo(i,med)){
					sup=med;
				}else{
					inf=med;
				}
			}
			puntos[i]=sup;
		}
		
		for(int i=0;i<N;++i){
			res[i]=max(0.0,(double)puntos[i]/(double)X);
			res[i]*=100.0;
		}
		cout << "Case #" << caso << ":";
		for(int i=0;i<N;++i){
			printf(" %.10lf",res[i]);
		}
		cout << endl;
	}
	return 0;
}
