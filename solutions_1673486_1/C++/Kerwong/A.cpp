#include <iostream>
#include <fstream>
#include <hash_map>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	ifstream fin("./A-large.in");
	ofstream fout("./output.out");
	if(!fin) {
		cerr<<"文件input打开失败"<<endl;
		return -1;
	}
	if(!fout) {
		cerr<<"文件output打开失败"<<endl;
		return -1;
	}
	
	int T;
	int entered, length;
	double best = 0.0,rate=1.0,rs;
	fin>>T;
	vector<double> dv;
	for(int cases = T; cases!=0; --cases) {
		fin>>entered>>length;
		double tmp=0.0;
		for(int i=0; i<entered; i++){
			fin>>tmp;
			dv.push_back(tmp);
		}
		
		best = 2 + length;
		for(int i = 0; i<(entered+1); i++){
			for(int j=entered-i-1; j>=0; --j){
				rate *= dv[j];
			}
			rs = (i*2+length-entered+1)*rate + (1-rate)*(length+length-entered+2+2*i);
			rate = 1.0;
			if(rs<best) best=rs;
		}

		fout<<"Case #"<<T - cases + 1<<": "<<setprecision(6)<<std::fixed<<best<<endl;
		dv.clear();
	}
	return 0;
}