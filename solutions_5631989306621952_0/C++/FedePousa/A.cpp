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

string S;

string solve(int hasta){
	if(hasta==0){
		return "";
	}
	int maxi = 0;
	for(int i=0; i<hasta; ++i){
		if(S[i]>=S[maxi]){
			maxi = i;
		}
	}
	string res1 = "";
	for(int j=maxi+1; j<hasta; ++j){
		res1.push_back(S[j]);
	}
	string res = S[maxi] + solve(maxi) + res1;
	return res; 
}

int main(){
	int T;
	cin >> T;
	for(int caso=1; caso<=T; ++caso){		
		cin >> S;
		string res = solve(S.size());
		cout << "Case #" << caso << ": " << res << endl; 
	}
	return 0;
}
