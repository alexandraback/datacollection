#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	ifstream ifs;
	ifs.open("A-large.in");
	ofstream ofs;
	ofs.open("output.txt");
	int T; ifs>>T;
	for(int i=1;i<=T;++i){
		int s_max;
		string s;
		ifs>>s_max>>s;
		vector<int> sVec(s.size());
		for(int j=0;j<s.size();++j){
			sVec[j] = s[j] - '0';
		}

		int min = 0;
		int tNow = sVec[0];
		for(int j=1;j<sVec.size();++j){
			if(sVec[j] != 0){
				if(tNow < j){
					min += j-tNow;
					tNow = j;
				}
				tNow += sVec[j];
			}
		}

		ofs<<"Case #"<<i<<": "<<min<<endl;

	}
	return 0;
}