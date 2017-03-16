#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;


int main(){
	int cnt = 0;
	vector <long long> vl;
	for(long long i=1;i<=10000000;i++){
		ostringstream oss;
		oss << i;
		long long j = i*i;
		string s = oss.str();
		reverse(s.begin(),s.end());
		if(s==oss.str()){
			ostringstream oss2;
			oss2 << j;
			s = oss2.str();
			reverse(s.begin(),s.end());
			if(s == oss2.str()) vl.push_back(j);
		}
	}
	cout << "Please download data and press any key when ready" << endl;
	char c;
	cin >> c;

	ifstream fin("C-small-attempt0.in");
	ofstream fout("C-small0.out");
	int T;
	fin >> T;
	for(int t=0;t<T;t++){
		long long A,B;
		fin >> A >> B;
		int cnt=0;
		for(int i=0;i<vl.size();i++)
			if(A<=vl[i] && vl[i]<=B) cnt++;
		fout <<"Case #"<< t+1<< ": " << cnt << endl;

	}
	
	return 0;
}

