//============================================================================
// Name        : PanCake.cpp
// Author      : Yul Obraz
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

int simplify(int caseId){
	bool firstMinus=caseId<0;
	bool lastMinus= (caseId>0)?(caseId%2==0):((-caseId)%2==1);
	if(!firstMinus){
		return -(caseId-1);
	}
	return (-caseId)-(lastMinus?0:1);
}
int calc(string target){
	int n = target.length();
	const char*line=target.c_str();
	char prev=line[0];
	int caseId=1;
	for(int i=0;i<n;i++){
		if(prev!=line[i]){
			prev = line[i];
			caseId++;
		}
	}
	if(line[0]=='-'){
		caseId=-caseId;
	}
	int transformes =0;
	while(caseId!=1){
		caseId = simplify(caseId);
		transformes++;
	}
	return transformes;
}

int main(int argc,char *argv[]) {
	freopen(argv[1],"r",stdin);
	freopen(argv[2],"w",stdout);
	int tests;
	cin >> tests;
	for(int i=0; i<tests; i++){
		string target;
		cin>>target;
		//std::getline(cin, target);
		//getline(cin, &str);

		int result = calc(target);
		cout << "Case #"<< (i+1)<<": "<<result<< endl;
	}
	return 0;
}
