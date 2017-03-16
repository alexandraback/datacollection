/*Santiago Zubieta*/
#include <iostream>
#include <numeric>
#include <fstream>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

vector <int> arrc[1001];
long long int clases;
long long int num;
long long int cases;
long long int n;
long long int K;
long long int J;

int DFS(int j){
	int res = 0;
	if(j==K){
		return 1;
	}
	for(int x=0; x<arrc[j].size(); ++x){
		res += DFS(arrc[j][x]);
	}
	return res;
}


int main(){
	cin >> cases;
	bool caso;
	for(int i=0; i<cases; i++){
		cin >> clases;
		for(int x=0; x<1001; x++){
			arrc[x].clear();
		}
		
		for(int j=0; j<clases; ++j){
			cin >> num;
			for(int k=0; k<num; ++k){
				cin >> n;
				arrc[j].push_back(n-1);
			}
		}
		caso = false;
		for(int j=0; j<clases; ++j){
			for(int k=0; k<clases; ++k){
				J = j;
				K = k;
				if(j==k){
					continue;
				}
				if(DFS(j)>=2){
					caso = true;
				}
			}
		}
		cout << "Case #" << i+1 << ":";
		if(caso){ 
			cout << " Yes" << endl;
		}
		else{
			cout << " No" << endl;
		}
	}
}