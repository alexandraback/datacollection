//============================================================================
// Name        : codeJamRound1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
int t,s;
int a[1001];
char ch;
int main() {
	ifstream in("input");
	ofstream out("output");
	in>>t;
	for(int p = 0; p < t; p++){
		in>>s;
		int number = 0;
		for (int i = 0; i <=s; i++){
			in>>ch;
			a[i] = (int)ch - (int)'0';
			number +=a[i];
		}
		bool f = true;
		int cur = a[0],begin = 1;
		while (f){
			f = false;
			int k = cur;
			for (int j = begin; j <= min(k,s); j++){
				cur +=a[j];
				a[j] = 0;
			}
			begin = k+1;
			if (k != cur)
				f = true;
		}
		if (number != cur){
			int add = 0;
			for(int i = cur+1; i<=s; i++){
				if (a[i] > 0 && cur+add < i){
					add = i - cur;
				}
				cur += a[i];
			}
			out<<"Case #"<<p+1<<": "<<add<<'\n';
		}else{
			out<<"Case #"<<p+1<<": "<<0<<'\n';
		}
	}
	return 0;
}
