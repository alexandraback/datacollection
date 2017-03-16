#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<climits>
#include<stack>
#include <iomanip>      // std::setprecision
#include<stdlib.h>
#define outr(x,y) fout<<"Case #"<<x+1<<": "<<y<<endl;

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

string findMin(unsigned long long P, unsigned long long Q){

	int itr = 0;
	int floc=999;
	string res;
	double ratio;
	//cout << ratio<< endl;

	while (itr < 40 && P!=0){

		P *= 2;
		ratio= 1.0* P / Q;
		if (ratio >= 1){ if (floc>itr)floc = itr+1;  P -= Q; }

		itr++;
	}
	if (P == 0 || P==Q) return to_string(floc);
	else return "impossible";

}
int main(){
	int T;
	unsigned long long P, Q;
	string s;
	fin >> T;
	for (int i = 0; i < T; i++){
		fin >> s;


		string delimiter = "/";
		
		size_t pos = 0;
		string token;
		while ((pos = s.find(delimiter)) != string::npos) {
			token = s.substr(0, pos);
			s.erase(0, pos + delimiter.length());
		}

		P = atoll(token.c_str());
		Q = atoll(s.c_str());
		outr(i, findMin(P, Q));
	}
	
	cin >> T;
	return 0;
}