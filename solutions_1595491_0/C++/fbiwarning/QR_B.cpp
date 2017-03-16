// QR_B.cpp : 定义控制台应用程序的入口点。
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
	infile.open("B-small-attempt2.in", fstream::in);
	outfile.open("B-small-attempt2.out", fstream::out);
	string line;

	int CaseNum;
	int N, S, p;
	int tmp, tmp2;
	vector< int > sum; 
	int total;
	int leftS;

	if(infile){
		infile >> CaseNum;
		for(int i=0; i<CaseNum; ++i){
			sum.clear();
			total = 0;
			// 获取数据
			infile >> N >> S >> p;
			for(int j=0; j<N; ++j){
				infile >> tmp;
				sum.push_back(tmp);
			}
			leftS = S;

			// 判断余数
			for(int j=0; j<sum.size(); ++j){
				tmp = sum[j]%3;
				tmp2 = sum[j] / 3;

				if(tmp ==  2){
					// 普通模式
					if(tmp2 + 1 >= p && tmp2 + 1 <= 10){
						++total;
					}
					// 惊奇模式
					else if(tmp2 + 2 >= p && leftS >0 && tmp2 + 2 <= 10){
						++total;
						--leftS;
					}

				}
				else if(tmp == 1){
					if(tmp2 + 1 >= p  && tmp2 + 1 <= 10){
						++total;
					}
				}
				else{
					if(tmp2 >= p){
						++total;
					}else if(tmp2 > 0 && tmp2 + 1 >= p && leftS >0 && tmp2 + 1 <= 10){
						++total;
						--leftS;
					}
				}
			}
			outfile << "Case #" << i+1 << ": ";
			outfile << total << endl;
		}
	}
	infile.close();
	outfile.close();
	return 0;
}

