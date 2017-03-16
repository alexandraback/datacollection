// R1B_A.cpp : 定义控制台应用程序的入口点。
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
	//infile.open("example.in", fstream::in);
	//outfile.open("example.out", fstream::out);
	infile.open("A-small-attempt3.in", fstream::in);
	outfile.open("A-small-attempt3.out", fstream::out);
	string line;

	int CaseNum;
	int N;
	vector<int> s;
	vector<double> r;
	vector<bool> f;
	int tmp;
	double sum;
	double sum2;
	double avg;
	double tmpD;
	int count;

	double result = 0;

	if(infile){
		infile >> CaseNum;
		for(int i=0; i<CaseNum; ++i){
			// 获取数据
			infile >> N;
			s.clear();
			r.clear();
			f.clear();
			for(int j=0; j<N; ++j){
				infile >> tmp;
				s.push_back(tmp);
			}	
			sum = 0;
			sum2 = 0;
			count = 0;
			for(int j=0; j<N; ++j){
				sum += s[j];
			}
			avg = sum*2/N;
			for(int j=0; j<N; ++j){
				tmpD = (avg - s[j])*100 / sum;
				if(tmpD < 0){
					f.push_back(true);
					continue;
				}
				sum2 += s[j];
				count ++;
				f.push_back(false);
			}
			
			avg = (sum2 + sum)/count;
			for(int j=0; j<N; ++j){
				if(!f[j]){
					tmpD = (avg - s[j])*100 / sum;
				}else{
					tmpD = 0;
				}
				r.push_back(tmpD);
			}


			outfile << "Case #" << i+1 << ": ";
			outfile << setprecision(7);
			for(int j=0; j<N; ++j){
				outfile << fixed << setprecision(7)<< r[j] << " ";
			}
			outfile << endl;

			cout << "Case #" << i+1 << ": ";
			cout << setprecision(7);
			for(int j=0; j<N; ++j){
				cout << fixed << setprecision(7)<< r[j] << " ";
			}
			cout << endl;
		}
	}
	infile.close();
	outfile.close();
	return 0;
}

