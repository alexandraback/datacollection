// R1A_B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <math.h>
#include <algorithm>
using namespace std;

int findLevel(int star, vector<int> &l, vector<bool> &flag){
	for(unsigned i=0; i<l.size(); ++i){
		if(!flag[i] && star >= l[i] ){
			return i;
		} 
	}
	return -1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	fstream infile, outfile;
	infile.open("B-small-attempt2.in", fstream::in);
	outfile.open("B-small-attempt2.out", fstream::out);
	string line;

	int CaseNum;
	int N;
	vector<int> a;
	vector<int> b;
	vector<bool> flagA;
	vector<bool> flagB;
	int tmpA, tmpB;
	int result = 0;
	int star = 0;
	int index = 0;

	if(infile){
		infile >> CaseNum;
		for(int i=0; i<CaseNum; ++i){
			star = 0;
			result = 0;
			a.clear();
			b.clear();
			flagA.clear();
			flagB.clear();

			infile >> N;
			// 获取数据
			for(int j=0; j<N; ++j){
				infile >> tmpA >> tmpB;
				a.push_back(tmpA);
				b.push_back(tmpB);
				flagA.push_back(false);
				flagB.push_back(false);
			}
			int count = b.size();
			
			// 在L2找
			while(count > 0){
				index = findLevel(star, b, flagB);
				if(index >= 0){
					if(!flagA[index]){
						star += 2;
					}else{
						star += 1;
					}
					flagB[index] = true;
					result += 1;
					count--;
				}else{
					// L1
					index = findLevel(star, a, flagA);
					if(index >= 0){
						star += 1;
						flagA[index] = true;
						result += 1;
					}else{
						break;
					}
				}
			}
			if(count > 0){
				outfile << "Case #" << i+1 << ": ";
				outfile << "Too Bad" << endl;
				cout << "Case #" << i+1 << ": ";
				cout << "Too Bad" << endl;
			}else{
				
				outfile << "Case #" << i+1 << ": ";
				outfile << result << endl;
				cout << "Case #" << i+1 << ": ";
				cout << result << endl;
			}
		}
	}
	infile.close();
	outfile.close();
	return 0;
}

