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

bool isPal(long long int i){
	stringstream ss;
	ss << i;
	string s = ss.str();
	for(int i=0;i<(int)s.size();++i){
		if(s[i]!=s[s.size()-1-i])return false;
	}
	return true;
}

int main(){
	int T;
	long long A, B;
	vector<long long> vec;
	for(long long int i=1;i<10000000;++i){
		if(isPal(i)&&isPal(i*i)){
			//~ cout << i*i << endl;
			vec.push_back(i*i);
		}
	}
	
	cin >> T;
	for(int caso=1;caso<=T;++caso){
		cin >> A >> B;
		cout << "Case #" << caso << ": " << upper_bound(vec.begin(), vec.end(),B)-upper_bound(vec.begin(), vec.end(),A-1) << endl;
	}
	
	return 0;
}
