#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#define TEST 0
#define DEBUG 0

string solve(string s){
	if (s.size() == 1)
		return s;
	int len = s.size();
	string str = s.substr(0,1);
	for(int i = 1; i < s.size(); i++){
		if( s[i] >= str[0])
			str = s.substr(i,1) + str;
		else
			str = str + s.substr(i,1);
	}
	return str;
}

int main() {
	int T;
    input >> T;

	string filename = "A-small-attempt0";
	ifstream input(filename + ".in");
#if TEST	
	ofstream output(filename + ".out");
#endif

	for(int T_i = 1; T_i <= T; T_i++){

   		string S;
        input >>  S;

#if TEST		
		output << "Case #" << T_i << ": " << solve(S) << endl;
#else
		cout << "Case #" << T_i << ": " << solve(S) << endl;
#endif				
	}

    
	return 0;
}
