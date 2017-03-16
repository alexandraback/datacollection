/*
 * a.cpp
 *
 *  Created on: 2012-4-14
 *      Author: cj
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>

using namespace std;

const char trans[27] = {"yhesocvxduiglbkrztnwjpfmaq"};

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ncase; 	char str[110];
	cin >> ncase;
	cin.getline(str, 2);
	for(int i = 0; i < ncase; i++){
		cin.getline(str, 110);
		cout << "Case #" << i + 1 << ": ";
		int l = strlen(str);
		for(int i = 0; i < l; i++){
			if(str[i] == ' ') cout << ' ';
			else cout << trans[str[i] - 'a'];
		}
		cout << endl;
	}
/*	for(int i = 0; i < 3; i++){
		char str1[100], str2[100];
		cin.getline(str1, 100);
		cin.getline(str2, 100);
		int l = strlen(str1);
		for(int j = 0; j < l; j++){
			if(str1[j] == ' ') continue;
			trans[str1[j] - 'a'] = str2[j];
		}
	}
	cout << '"';
	for(int i = 0; i < 26; i++)
		cout << char('a' + i);
	cout << '"';
	cout << endl << '"';
	for(int i = 0; i < 26; i++)
		cout << trans[i];
	cout << '"';*/

	return 0;
}




