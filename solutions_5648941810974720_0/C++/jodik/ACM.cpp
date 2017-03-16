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

int main() {
	int cases;
	cin>>cases;
	for(int i = 0; i < cases; i++){
		string word;
		cin>>word;
		int cislice[10];
		int pismenka['Z' + 10];
		for(int j = 0; j <= 'Z' + 10; j++){
			pismenka[j] = 0;
		}
		for(char c : word){
			pismenka[c]++;
		}
		cislice[0] = pismenka['Z'];
		pismenka['E']-=pismenka['Z'];
		pismenka['R']-=pismenka['Z'];
		pismenka['O']-=pismenka['Z'];

		cislice[4] = pismenka['U'];
		pismenka['F']-=pismenka['U'];
		pismenka['R']-=pismenka['U'];
		pismenka['O']-=pismenka['U'];

		int tmp;
		tmp = pismenka['X'];
		cislice[6] = tmp;
		pismenka['S']-=tmp;
		pismenka['I']-=tmp;
		pismenka['X']-=tmp;

		tmp = pismenka['W'];
		cislice[2] = tmp;
		pismenka['T']-=tmp;
		pismenka['W']-=tmp;
		pismenka['O']-=tmp;

		tmp = pismenka['G'];
		cislice[8] = tmp;
		pismenka['E']-=tmp;
		pismenka['I']-=tmp;
		pismenka['H']-=tmp;
		pismenka['T']-=tmp;

		cislice[1] = pismenka['O'];
		pismenka['N'] -= pismenka['O'];
		cislice[7] = pismenka['S'];
		pismenka['N'] -= pismenka['S'];
		cislice[3] = pismenka['R'];
		cislice[5] = pismenka['F'];
		cislice[9] = pismenka['N']/2;

		string res = "";
		for(int j = 0; j < 10; j++){
			tmp = cislice[j];
			while(tmp--){
				res+=('0'+j);
			}
		}

		cout<<"Case #"<<i+1<<": "<<res<<endl;
	}
}
