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

int coutRecycle(int n, int Max, int Min, char list[]){
	stringstream ss;
	string numberList;
	string number;
	int count = 0;
	int curNumber = 0;

	ss << n << n;
	numberList = ss.str();

	for(int i=1; i<numberList.size()-1; ++i){
		number = numberList.substr(i, numberList.size()/2);
		curNumber = atoi(number.c_str());

		if(curNumber >= Min && curNumber <= Max && curNumber != n){
			if(list[curNumber] != 1){
				++count;
				list[curNumber] = 1;
			}
		}
	}
	if(count > 0){
		list[n] = 1;
	}
	return (count+1)*(count)/2;
}

char list[2000001] = {0};
int _tmain(int argc, _TCHAR* argv[])
{
	fstream infile, outfile;
	infile.open("C-large.in", fstream::in);
	outfile.open("C-large.out", fstream::out);
	
	int CaseNum;
	int A, B;
	
	int count;

	if(infile){
		infile >> CaseNum;
		for(int i=0; i<CaseNum; ++i){
			memset(list, 0, 2000001);
			infile >> A >> B;
			count = 0;
			for(int n=A; n<=B; ++n){
				if(list[n] == 1){
					continue;
				}
				count += coutRecycle(n, B, A, list);

			}
			outfile << "Case #" << i+1 << ": ";
			outfile << count << endl;
			cout << "Case #" << i+1 << ": ";
			cout << count << endl;
		}
	}
	infile.close();
	outfile.close();
	return 0;
	return 0;
}

