//============================================================================
// Name        : ACM.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <curl/curl.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cmath>
#include <fstream>

using namespace std;

vector<pair<string, string> > dic;
vector<int> permutation;
int couples;
int res = 0;

void check(){
	set<string> firstWords;
	set<string> secondWords;
	int fakes = 0;
	for(int i = 0; i < couples; i++){
		if(permutation[i]){
			firstWords.insert(dic[i].first);
			secondWords.insert(dic[i].second);
		}
	}
	for(int i = 0; i < couples; i++){
		if(!permutation[i]){
			fakes++;
			if(firstWords.count(dic[i].first) == 0){
				return;
			}
			if(secondWords.count(dic[i].second) == 0){
				return;
			}
		}
	}
	res = max(fakes, res);
}

void cpermutation(int i){
	if(i == couples){
		check();
		return;
	}
	else {
		permutation[i] = 0;
		cpermutation(i + 1);
		permutation[i] = 1;
		cpermutation(i + 1);
	}
}

int main() {
	int cases;
	cin>>cases;
	for(int i = 0; i < cases; i++){
		pair<string, string> couple;
		res = 0;
		dic.clear();
		cin>>couples;
		permutation.clear();
		permutation.resize(couples, 0);
		for(int j = 0; j < couples; j++){
			cin>>couple.first;
			cin>>couple.second;
			dic.push_back(couple);
		}
		cpermutation(0);

		cout<<"Case #"<<i+1<<": "<<res<<endl;
	}
}
