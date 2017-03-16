//============================================================================
// Name        : codejamA.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

string solve(){
	string res[10];
	bool isdot = false;
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			char a;
			cin>>a;
			if(a == '.'){
				isdot = true;
			}
			res[i].push_back(a);
			res[j+4].push_back(a);
			if(i==j){
				res[8].push_back(a);
			}
			if(i == 3-j){
				res[9].push_back(a);
			}
		}
	}
	const char * o = "O";
	const char * x = "X";
	for(int i=0; i<10; ++i){
		string tmpo = res[i];
		string tmpx = res[i];
		size_t t = res[i].find('T');
		if(t != res[i].npos){
			tmpo = res[i].replace(t, 1, o);
			tmpx = res[i].replace(t, 1, x);
		}
		if(tmpo == "OOOO"){
			return "O won";
		}else if(tmpx == "XXXX"){
			return "X won";
		}
	}
	if(isdot){
		return "Game has not completed";
	}else{
		return "Draw";
	}
}

int main() {
	int T;
	cin>>T;
	for(int i=0; i<T; ++i){
		string ans = solve();
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}
