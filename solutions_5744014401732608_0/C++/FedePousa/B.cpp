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
		long long B, M;
		cin >> B >> M;
		cout << "Case #" << caso << ": ";
		if(1LL<<(B-2)<M){
			cout << "IMPOSSIBLE" << endl;
			continue;
		} 
		if(1LL<<(B-2)==M){
			cout << "POSSIBLE" << endl;
			//matriz completa
			for(int i=0; i<B; ++i){
				for(int j=0; j<B; ++j){
					if(i>=j){
						cout << "0";
					}else{
						cout << "1";
					}
				}
				cout << endl;
			}
			continue;
		}
		cout << "POSSIBLE" << endl;
		cout << "0";
		for(int i=B-3; i>=0; i--){
			if(M&(1LL<<i)){
				cout << "1";
			}else{
				cout << "0";
			}
		}
		cout << "0" << endl;
		for(int i=1; i<B; ++i){
			for(int j=0; j<B; ++j){
				if(i>=j){
					cout << "0";
				}else{
					cout << "1";
				}
			}
			cout << endl;
		}	
	}
	
	return 0;
}
