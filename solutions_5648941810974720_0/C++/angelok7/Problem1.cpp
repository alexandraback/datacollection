#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

string arr[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main()
{
	int t,T;
	ifstream fin("A-small-attempt0.in");
	ofstream fout("output.txt");
	
	fin>>T;

	vector<vector<int> > kk(10,vector<int>(26));
	for(int i=0;i<10;i++){
		for(int j=0;j<arr[i].size();j++)
			kk[i][arr[i][j] - 'A']++;
	}

	for(t=0;t<T;t++){
		string s;
		fin>>s;
		vector<int> input;
		vector<int> res;
		res.clear();
		input.clear();
		input.resize(26,0);
		res.resize(10,0);
		for(int i=0;i<s.size();i++){
			input[s[i]-'A']++;
		}

		if(input['Z'-'A'] > 0){
			res[0] = input['Z'-'A'];
			for(int i=0;i<26;i++) input[i] -= (res[0] * kk[0][i]);
		}

		if(input['W'-'A'] > 0){
			res[2] = input['W'-'A'];
			for(int i=0;i<26;i++) input[i] -= (res[2] * kk[2][i]);
		}

		if(input['U'-'A'] > 0){
			res[4] = input['U'-'A'];
			for(int i=0;i<26;i++) input[i] -= (res[4] * kk[4][i]);
		}

		if(input['X'-'A'] > 0){
			res[6] = input['X'-'A'];
			for(int i=0;i<26;i++) input[i] -= (res[6] * kk[6][i]);
		}

		if(input['G'-'A'] > 0){
			res[8] = input['G'-'A'];
			for(int i=0;i<26;i++) input[i] -= (res[8] * kk[8][i]);
		}

		if(input['O'-'A'] > 0){
			res[1] = input['O'-'A'];
			for(int i=0;i<26;i++) input[i] -= (res[1] * kk[1][i]);
		}

		if(input['T'-'A'] > 0){
			res[3] = input['T'-'A'];
			for(int i=0;i<26;i++) input[i] -= (res[3] * kk[3][i]);
		}

		if(input['F'-'A'] > 0){
			res[5] = input['F'-'A'];
			for(int i=0;i<26;i++) input[i] -= (res[5] * kk[5][i]);
		}

		if(input['V'-'A'] > 0){
			res[7] = input['V'-'A'];
			for(int i=0;i<26;i++) input[i] -= (res[7] * kk[7][i]);
		}

		if(input['E'-'A'] > 0){
			res[9] = input['E'-'A'];
			for(int i=0;i<26;i++) input[i] -= (res[9] * kk[9][i]);
		}
		string result = "";
		for(int i=0;i<10;i++){
			char a = '0' + i;
			for(int j=0;j<res[i];j++)
				result += a;
		}
		fout<<"Case #"<<t+1<<": "<<result<<endl;
	}


	return 0;
}


//fout.setf(ios::fixed);
//fout.precision(6);