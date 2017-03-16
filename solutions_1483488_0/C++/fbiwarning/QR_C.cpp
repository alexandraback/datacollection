// QR_C.cpp : 定义控制台应用程序的入口点。
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
bool hasNumber(int n, vector<int> &list){
	for(int i=0; i<list.size(); ++i){
		if(n == list.at(i)){
			return true;
		}
	}
	return false;
}

int coutRecycle(int n, int Max, int Min, vector<int> &list){
	stringstream ss;
	string numberList;
	string number;
	int count = 0;
	int curNumber = 0;
	vector<int> tmplist;

	ss << n << n;
	numberList = ss.str();

	for(int i=1; i<numberList.size()-1; ++i){
		number = numberList.substr(i, numberList.size()/2);
		curNumber = atoi(number.c_str());

		if(curNumber >= Min && curNumber <= Max && curNumber != n){
			if(!hasNumber(curNumber, tmplist)){
				tmplist.push_back(curNumber);
				++count;
				list.push_back(curNumber);
			}
			
			//cout << curNumber << ' ';
		}
	}
	if(count > 0){
		list.push_back(n);
		//cout << n << endl;
	}
	return (count+1)*(count)/2;
}


int _tmain(int argc, _TCHAR* argv[])
{
	fstream infile, outfile;
	infile.open("C-small-attempt0.in", fstream::in);
	outfile.open("C-small-attempt0.out", fstream::out);
	
	int CaseNum;
	int A, B;
	vector<int> list;
	int count;

	if(infile){
		infile >> CaseNum;
		for(int i=0; i<CaseNum; ++i){
			infile >> A >> B;
			list.clear();
			count = 0;
			for(int n=A; n<=B; ++n){
				if(hasNumber(n, list)){
					continue;
				}
				count += coutRecycle(n, B, A, list);

			}
			outfile << "Case #" << i+1 << ": ";
			outfile << count << endl;
		}
	}
	infile.close();
	outfile.close();
	return 0;
	return 0;
}

