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

int T, E, R, N, acti[10005], maxi;

void solve(int act, int ener, int voy){
	if(act==N){
		maxi = max(maxi, voy);
		return;
	}
	for(int i=0;i<=ener;++i){
		solve(act+1, min(E,ener-i+R),voy+(i*acti[act])); 
	}
	return;
}

int main(){
	cin >> T;
	for(int caso=1;caso<=T;++caso){
		cin >> E >> R >> N;
		maxi = 0;
		for(int i=0;i<N;++i){
			cin >> acti[i];
		}
		solve(0, E, 0);
		cout << "Case #" << caso << ": " << maxi << endl;
	}
	
	return 0;
}
