// R1A_A.cpp : 定义控制台应用程序的入口点。
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

int _tmain(int argc, _TCHAR* argv[])
{
	fstream infile, outfile;
	infile.open("A-small-attempt3.in", fstream::in);
	outfile.open("A-small-attempt3.out", fstream::out);
	string line;

	int CaseNum;
	int A, B;
	int N;
	double tmp;
	vector<double> ps;
	double p=1.0f;
	double result = 0;

	if(infile){
		infile >> CaseNum;
		for(int i=0; i<CaseNum; ++i){
			p=1.0f;
			ps.clear();
			infile >> A >> B;
			// 获取数据
			for(int j=0; j<A; ++j){
				infile >> tmp;
				ps.push_back(tmp);
			}

			// 计算第3个情况
			result = (double)B+2.0f;
			cout << result << ", ";

			// 计算第1 2 情况
			for(int j=0; j<=A; ++j){
				p= 1.0f;
				N = A-j;
				for(int n=0; n<N; ++n){
					p = p* ps[n];
				}
				tmp = (double)(B-N+1)*p + (double)(B-N+1+B+1)*(1.0f-p) + (double)j;
				cout << tmp << ", ";

				if(result >= tmp){
					result = tmp;
				}
			}
			cout << endl;
			
			outfile << "Case #" << i+1 << ": ";
			outfile << setprecision(6);
			outfile << fixed << setprecision(6)<< result << endl;
			cout << "Case #" << i+1 << ": ";
			
			cout << fixed << setprecision(6)<< result << endl;
		}
	}
	infile.close();
	outfile.close();
	return 0;
}

