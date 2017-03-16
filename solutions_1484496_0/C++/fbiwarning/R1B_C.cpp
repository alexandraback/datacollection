// R1B_C.cpp : 定义控制台应用程序的入口点。
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
bool   greatermark(const   int   &s1,const  int   &s2)  
{  
  return   s1 < s2;  
}
int hasSame(vector<int> &list, int value){
	for(unsigned i=0; i<list.size(); ++i){
		if(value == list[i]){
			return i;
		}
	}
	return -1;
}
int sum(vector <int> &sub){
	int s = 0;
	for(unsigned i=0; i<sub.size(); ++i){
		s += sub[i];
	}
	return s;
}
void genSubs(vector< vector<int> > &result, vector<int> &s){
	vector< vector<int> > subs;
	vector<int> list;

	for(unsigned i=0; i<s.size(); ++i){
		if(subs.size()==0){
			vector<int> tmp;
			tmp.push_back(s[i]);
			subs.push_back(tmp);
			list.push_back(s[i]);
		}else{
			unsigned size = subs.size();
			vector<int> tmp;
			tmp.push_back(s[i]);
			int tSum = sum(tmp);
			int index = hasSame(list,tSum);
			if(index >= 0){
				result.push_back(subs[index]);
				result.push_back(tmp);
				return;
			}else{
				subs.push_back(tmp);
				list.push_back(tSum);
			}
			
			
			for(unsigned j=0; j<size; ++j){
				vector<int> tmp;
				tmp.push_back(s[i]);
				for(unsigned m=0; m<subs[j].size(); ++m){
					tmp.push_back(subs[j][m]);
				}
				int tSum = sum(tmp);
				int index = hasSame(list,tSum);
				if(index >= 0){
					result.push_back(subs[index]);
					result.push_back(tmp);
					return;
				}else{
					subs.push_back(tmp);
					list.push_back(tSum);
				}
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	fstream infile, outfile;
	//infile.open("example.in", fstream::in);
	//outfile.open("example.out", fstream::out);
	infile.open("C-small-attempt0.in", fstream::in);
	outfile.open("C-small-attempt0.out", fstream::out);
	string line;

	int CaseNum;
	int N;
	vector<int> s;
	int tmp;

	double result = 0;

	if(infile){
		infile >> CaseNum;
		for(int i=0; i<CaseNum; ++i){
			infile >> N;
			s.clear();
			for(int j=0; j< N; ++j){
				infile >> tmp; 
				s.push_back(tmp);
			}
			sort(s.begin(), s.end(), greatermark)   ;   //降序排序

			vector< vector<int> > subs;
			genSubs(subs, s);

			outfile << "Case #" << i+1 << ": " << endl;
			if(subs.size() > 0){
				for(unsigned j=0; j<subs.size(); ++j){
					for(unsigned m=0; m<subs[j].size(); ++m){
						outfile << subs[j][m] << " ";
					}
					outfile << endl;
				}
			}
			cout << "Case #" << i+1 << ": " << endl;
			if(subs.size() > 0){
				for(unsigned j=0; j<subs.size(); ++j){
					for(unsigned m=0; m<subs[j].size(); ++m){
						cout << subs[j][m] << " ";
					}
					cout << endl;
				}
			}
		}
	}
	infile.close();
	outfile.close();
	return 0;
}
