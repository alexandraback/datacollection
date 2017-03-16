#include <cstdlib>
#include <map>
#include <algorithm>
#include<iostream>
#include <vector>
#include <string>
#include<fstream>
using namespace std;

bool extract(map<char,int> & count, string letters) {
	for(int i = 0; i < letters.size(); ++i) {
		if (count[letters[i]] == 0) {
			return false;
		}
	}
	for(int i = 0; i < letters.size(); ++i) {
		count[letters[i]]--;
	}
	return true;
}

int main(int argc, char** argv) {
	int T;
	string S;
	ifstream fin("A-small-attempt0.in");
	ofstream fo("A.small.out");
	fin >> T;
	vector<string> ord;
	ord.push_back("ZERO");
	ord.push_back("TWO");
	ord.push_back("SIX");
	ord.push_back("SEVEN");
	ord.push_back("FIVE");
	ord.push_back("FOUR");
	ord.push_back("EIGHT");
	ord.push_back("THREE");
	ord.push_back("NINE");
	ord.push_back("ONE");
	map<char,int> count;
	map<string,int> mapping;
	mapping["ZERO"] = 0;
	mapping["ONE"] = 1;
	mapping["TWO"] = 2;
	mapping["THREE"] = 3;	
	mapping["FOUR"] = 4;	
	mapping["FIVE"] = 5;	
	mapping["SIX"] = 6;	
	mapping["SEVEN"] = 7;	
	mapping["EIGHT"] = 8;	
	mapping["NINE"] = 9;	
	
	vector<int> ret;
	for (int t = 1; t <= T; ++t) {
		fin >> S;
		count.clear();
		ret.clear();
		for(int j = 0; j < S.size(); ++j) {
			count[S[j]]++;
		}
		for(auto & letters : ord) {
			while (extract(count, letters)) {
				ret.push_back(mapping[letters]);
			}
		}
		sort(ret.begin(), ret.end());
		fo << "Case #" << t << ": ";
		for (int i = 0; i < ret.size(); ++i)
			fo << ret[i];
		fo << endl;
	}
	return 0;
}

