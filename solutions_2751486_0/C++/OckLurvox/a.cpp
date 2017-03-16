/*
 * a.cpp
 *
 *  Created on: 12-05-2013
 *      Author: Ock
 */

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

ifstream scanner;
ofstream out;
int L;
int n;
int T;
string s;
int testcase;

bool isCons(char c){
	return c!='a' && c!='e' && c!='i' && c!='o' && c!='u';
}

int countCons(string str){

	int maxc=0;
	int count = 0;
	for (int i = 0; i < str.length(); ++i) {
		if(isCons(str[i])){
			count++;
		}
		else
			count=0;

		if(maxc < count)
			maxc=count;
	}

	return maxc;
}

void solve(){

	int nVal=0;
	for (int i = 0; i < L; ++i) {
		for (int j = i; j < L; ++j) {
			string str = s.substr(i,j-i+1);
			int num = countCons(str);
			if(n<=num)
				nVal++;

		}
	}

	out << "Case #" << testcase << ": " << nVal << endl;

//	cout << "Case #:"<< testcase << " " << nVal << endl;
}

int main(){

	scanner.open("A-small-attempt0.in");
	out.open("output.txt");

	scanner >> T;
	for (int i = 1; i <= T; ++i) {
		testcase = i;
		scanner >> s >> n;
		L = s.length();
		solve();
	}



	scanner.close();
	out.close();


	return 0;
}

