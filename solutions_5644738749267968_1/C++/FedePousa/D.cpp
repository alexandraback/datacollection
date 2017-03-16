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
	int T, N, dres, res, resAct;
	vector<double> naomi, cual;
	vector<double> ken, auxV;
	double aux;
	cin >> T;
	for(int caso=1;caso<=T;caso++){
		ken.clear();
		naomi.clear();
		cin >> N;
		for(int i=0;i<N;i++){
			cin >> aux;
			naomi.push_back(aux);
		}
		for(int i=0;i<N;i++){
			cin >> aux;
			ken.push_back(aux);
		}
		sort(naomi.begin(),naomi.end());
		sort(ken.begin(),ken.end());
		
		//~ for(int i=0;i<N;i++){
			//~ cerr << naomi[i] << " ";
		//~ }
		//~ cerr << endl;
		//~ for(int i=0;i<N;i++){
			//~ cerr << ken[i] << " ";
		//~ }
		//~ cerr << endl;
		
		auxV = ken;
		
		
		res = 0;
		for(int i=0;i<N;i++){
			if(upper_bound(ken.begin(),ken.end(),naomi[i])!=ken.end()){
				ken.erase(upper_bound(ken.begin(),ken.end(),naomi[i]));
			}else{
				ken.erase(ken.begin());
				res++;
			}
		}
		
		
		dres = -1;
		sort(naomi.begin(),naomi.end());
		//~ do{
			//~ ken = auxV;
			//~ resAct = 0;
			//~ for(int i=0;i<N;i++){
				//~ if(naomi[i]>ken[0]){
					//~ resAct++;
					//~ ken.erase(ken.begin());
				//~ }else{
					//~ ken.erase(ken.end()-1);
				//~ }
			//~ }
			//~ if(resAct>dres){
				//~ cual = naomi;
			//~ }
			//~ dres = max(dres, resAct);
		//~ }while(next_permutation(naomi.begin(),naomi.end()));
		
		
		ken = auxV;
		resAct = 0;
		for(int i=0;i<N;i++){
			if(naomi[i]>ken[0]){
				resAct++;
				ken.erase(ken.begin());
			}else{
				ken.erase(ken.end()-1);
			}
		}
		dres = max(dres, resAct);
		
		
		
		
		
		cout << "Case #" << caso << ": " << dres << " " << res << endl;
		//~ for(int i=0;i<N;i++){
			//~ cerr << auxV[i] << " ";
		//~ }
		//~ cerr << endl;
		//~ for(int i=0;i<N;i++){
			//~ cerr << cual[i] << " ";
		//~ }
		//~ cerr << endl;
		//~ 
	}
	return 0;
}
