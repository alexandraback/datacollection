// QR_A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
#include <algorithm>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	fstream infile, outfile;
	infile.open("A-small-attempt0.in", fstream::in);
	outfile.open("A-small-attempt0.out", fstream::out);
	string line;

	int CaseNum;
	string match = "yhesocvxduiglbkrztnwjpfmaq";
	int index[26] = {0};
	int tmp = 0;
	for(int i=0; i<26; ++i){
		tmp = match[i] - 'a';
		index[i] = tmp;
	}
	string input = "";
	string result = "";
	stringstream ss;
	
	if(infile){
		infile >> CaseNum;
		getline(infile, input);
		for(int i=0; i<CaseNum; ++i){
			ss.clear();
			ss.str();
			result = "";
			getline(infile, input);
			for(int j=0; j<input.length(); ++j){
				if(input[j] == ' '){
					result += ' ';
					continue;
				}else{
					tmp = input[j] - 'a';
					result += ('a' + index[tmp]);
				}
			}
			outfile << "Case #" << i+1 << ": ";
			outfile << result << endl;
		}
	}
	infile.close();
	outfile.close();
	//string a[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", 
	//	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", 
	//	"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	//string b[3] = {"our language is impossible to understand", 
	//	"there are twenty six factorial possibilities", 
	//	"so it is okay if you want to just give up"};
	//
	//string result = "";
	//int index[26] = {0};
	//int flag[26] = {0};
	//int tmp = 0;

	//for(int k=0; k<3; k++){
	//	for(int i=0; i<a[k].length(); ++i){
	//		if(a[k][i] == ' '){
	//			continue;
	//		}
	//		tmp = a[k][i] - 'a';
	//		index[tmp] = b[k][i] - 'a';
	//		flag[tmp] = 1;
	//	}
	//}
	//for(int i=0; i<26; ++i){
	//	result += ('a'+index[i]);
	//}
	//cout << "abcdefghijklmnopqrstuvwxyz" << endl;
	//cout << result << endl;
	//for(int i=0; i<26; ++i){
	//	cout << flag[i];
	//}
	//cout <<endl;

	return 0;
}

