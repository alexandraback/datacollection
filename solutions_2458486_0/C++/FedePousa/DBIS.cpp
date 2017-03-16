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

typedef pair<int, vector<int> > pivi;

int main(){
	int T, K, N, aux, Ki, nece[30], quemeda[30][205], usado[1050000], llaves[205], llavesact[205];
	vector<int> res;
	bool posible;
	cin >> T;
	for(int caso=1;caso<=T;++caso){
		posible = false;
		memset(llaves, 0, sizeof llaves);
		memset(nece, 0, sizeof nece);
		memset(quemeda, 0, sizeof quemeda);
		memset(usado, 0, sizeof usado);
		cin >> K >> N;
		for(int i=0;i<K;++i){
			cin >> aux;
			llaves[aux]++;
		}
		for(int i=0;i<N;++i){
			cin >> nece[i];
			cin >> Ki;
			for(int j=0;j<Ki;++j){
				cin >> aux;
				quemeda[i][aux]++;
			}
		}
		
		
		queue< pivi> cola;
		pivi actual;
		int estactual;
		vector<int> nuevovec;
		cola.push(pivi(0, vector<int>()));
		while(!cola.empty()){
			actual = cola.front();
			estactual = actual.first;
			cola.pop();
			if(estactual == (1<<N)-1){
				//llegue
				if(!posible){
					res = actual.second;
					posible = true;
				}else{
					res = min(res, actual.second);
				}
			}
			for(int i=0;i<205;++i)llavesact[i] = llaves[i];
			for(int i=0;i<N;++i){
				if(!(estactual&(1<<i)))continue;
				llavesact[nece[i]]--;
				for(int j=0;j<205;++j){
					llavesact[j]+=quemeda[i][j];
				}
			}
			for(int i=0;i<N;++i){
				if(estactual&(1<<i))continue;
				if(usado[estactual|(1<<i)])continue;
				if(llavesact[nece[i]]){
					nuevovec = actual.second;
					nuevovec.push_back(i);
					cola.push(pivi(estactual|(1<<i), nuevovec));
					usado[estactual|(1<<i)] = 1;
				}
			}
		}

		cout << "Case #" << caso << ":";
		if(posible){
			for(int i=0;i<(int)res.size();++i){
				cout << " " << res[i]+1;
			}
			cout << endl;
		}else{
			cout << " IMPOSSIBLE" << endl;
		}
	}
	
	return 0;
}
