#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits> 
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t = 1; t < T + 1; t++){
		int C, D, V;
		cin >> C >> D >> V;
		int Ds[100];
		for(int d = 0; d < D; d++){
			cin >> Ds[d]; 
		}
		
		bool possible[10000];
		for(int v = 1; v < V + 1; v++){
			possible[v] = false;
		}
		possible[0] = true;
		
		for(int d = D - 1; d >= 0; d--){
			for(int v = V; v >= 0; v--){
				if(possible[v] == true){
					possible[v+Ds[d]] = true;
				}
			}
		}
		
		int total = 0;
		bool full = false;
		while(!full){
			full = true;
			for(int v = 1; v < V + 1; v++){
				if(!possible[v]){
					full = false;
					//cout << "F";
				}
				//else cout << "T";
			}
			//cout << endl;
			if(!full){
				int add = 0;
				for(int i = add + 1; i < 100; i++){
					bool rotate = false;
					for(int d = 0; d < D; d++){
						if(i == Ds[d]) rotate = true;
					}
					add = i;
					if(!rotate) break;
				}
				D++;
				Ds[D - 1] = add;
				//cout << add;
				for(int v = V; v >= 0; v--){
					if(possible[v] == true){
						possible[v+add] = true;
					}
				}
				total ++;
			}
		}
		
		cout << "Case #" << t << ": " << total << "\n";
	}
}
