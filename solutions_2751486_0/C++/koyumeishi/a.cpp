#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

#define REP(i,n) for (int i=0; i<n; i++)


bool isCC(string s){
	int l=s.size();
	int count=0;
	
	for(int i=0; i<l; i++){
		if(
			s.compare(i,1,"a")==0||
			s.compare(i,1,"e")==0||
			s.compare(i,1,"i")==0||
			s.compare(i,1,"o")==0||
			s.compare(i,1,"u")==0
		) break;
		count++;
	}
	if(count==l) return true;
	else return false;
}

int main(int argc, char *argv[]){
	int testcase=0;	//Nth test
	int X;	//testcase
	cout << "input file: " << argv[1] << endl;
	ifstream inputfile(argv[1]);
	ofstream outputfile("output.txt");
	
	inputfile >> X;
	
	REP(i,X){
		int count=0;
		testcase++;
		string S;
		int N;
		inputfile >> S >> N;
		cout << "S:" << S <<" N:" <<N<<endl;
		
		int l = S.size();
		vector<int> tmp;
		
		for(int i=0; i<=l-N; i++){
			if(isCC(S.substr(i,N))){
				int left,right;
				if(tmp.empty()) left=i;
				else left=i-tmp.back();
				right=l-(i+N);
				count += (left+1)*(right+1);
//				cout << "left:" << left <<" right:" << right <<endl;
//				cout << "count+:" << (left+1) * (right+1) <<endl;
//				cout << "count:" << count <<endl;
				tmp.push_back(i+1);
			}
		}
		
		
		cout << "Case #" << testcase << ": " << count << endl;
		outputfile << "Case #" << testcase << ": " << count << endl;
	}
	return 0;
}
