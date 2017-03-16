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

int ady[10][10];
vector<int> perm;

bool trans(int indice, int visite, stack<int> pila){
	
	//~ cerr << "Llamada"  << endl;
	//~ cerr << indice << " " << visite << endl;
	//~ stack<int> pila2 = pila;
	//~ while(!pila2.empty()){
		//~ cerr << pila2.top() << " ";
		//~ pila2.pop();
	//~ }
	//~ cerr << endl;
	if(!indice&&visite==(int)perm.size()&&pila.empty()){
		//~ cerr << "paso" << endl;
		return true;
	}
	int nuevoInd;
	if(indice==(int)perm.size()-1){
		nuevoInd = pila.top();
		pila.pop();
		//~ cerr << "metio" << endl;
		return trans(nuevoInd, visite, pila);
	}
	bool res = false;
	if(visite<(int)perm.size()&&ady[perm[indice]][perm[visite]]){
		pila.push(indice);
		res = trans(visite, visite+1, pila);
		pila.pop();
	}
	if(!pila.empty()){
		nuevoInd = pila.top();
		pila.pop();
		res = res || trans(nuevoInd, visite, pila);
	}
	return res;
}

int main(){
	int T, N, M, x, y;
	cin >> T;
	for(int caso=1;caso<=T;caso++){
		cin >> N >> M;
		string zip[10];
		for(int i=0;i<N;i++){
			cin >> zip[i];
		}	
		memset(ady,0,sizeof ady);
		for(int i=0;i<M;i++){
			cin >> x >> y;
			x--;
			y--;
			ady[x][y] = 1;
			ady[y][x] = 1;
		}
		
		string res = "99999999999999999999999999999999999999999999999999";
		
		
		if(N==1){
			cout << "Case #" << caso << ": " << zip[0] << endl;
			continue;
		}
		
		perm.clear();
		for(int i=0;i<N;i++){
			perm.push_back(i);
		}
		
		do{
			if(ady[perm[0]][perm[1]]){	
				//~ cerr << "a" << endl;
				//~ for(int i=0;i<N;i++){
					//~ cerr << perm[i] << " ";
				//~ }
				//~ cerr << endl;
				stack<int> pila;
				pila.push(0);
				bool sirve = trans(1, 2, pila);
				if(sirve){
					string aux = "";
					for(int i=0;i<(int)perm.size();i++){
						aux +=  zip[perm[i]];
					}
					res = min(res,aux);
				}
			}
			//~ break;
		}while(next_permutation(perm.begin(),perm.end()));
		cout << "Case #" << caso << ": " << res << endl;
	}
	
	return 0;
}
