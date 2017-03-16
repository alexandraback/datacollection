#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define FORI(A,B,C) for(int I=(A);I<=(B); I++)
#define FORLL(A,B,C) for(LL I=(A);I<=(B); I++)
#define VLL vector<LL>
#define VVLL vector<vector<LL>>
#define VI vector<int>
#define VVI vector<vector<int>>



string fun(string A){
	vector<int> cnt(26);
	string res;
	for (auto &x:A){
		cnt[x-'A']++;
	}
	while (cnt['Z'-'A']){
		res+='0';
		cnt['Z'-'A']--;
		cnt['E'-'A']--;
		cnt['R'-'A']--;
		cnt['O'-'A']--;
	}
	while (cnt['W'-'A']){
		res+='2';
		cnt['T'-'A']--;
		cnt['W'-'A']--;
		cnt['O'-'A']--;
	}
	while (cnt['U'-'A']){
		res+='4';
		cnt['F'-'A']--;
		cnt['O'-'A']--;
		cnt['U'-'A']--;
		cnt['R'-'A']--;
	}
	while (cnt['X'-'A']){
		res+='6';
		cnt['S'-'A']--;
		cnt['I'-'A']--;
		cnt['X'-'A']--;
	}
	while (cnt['G'-'A']){
		res+='8';
		cnt['E'-'A']--;
		cnt['I'-'A']--;
		cnt['G'-'A']--;
		cnt['H'-'A']--;
		cnt['T'-'A']--;
	}
	while (cnt['O'-'A']){
		res+='1';
		cnt['O'-'A']--;
		cnt['N'-'A']--;
		cnt['E'-'A']--;
	}
	while (cnt['H'-'A']){
		res+='3';
		cnt['T'-'A']--;
		cnt['H'-'A']--;
		cnt['R'-'A']--;
		cnt['E'-'A']--;
		cnt['E'-'A']--;
	}
	while (cnt['F'-'A']){
		res+='5';
		cnt['F'-'A']--;
		cnt['I'-'A']--;
		cnt['V'-'A']--;
		cnt['E'-'A']--;
	}
	while (cnt['V'-'A']){
		res+='7';
		cnt['S'-'A']--;
		cnt['E'-'A']--;
		cnt['V'-'A']--;
		cnt['E'-'A']--;
		cnt['N'-'A']--;
	}
	while (cnt['I'-'A']){
		res+='9';
		cnt['N'-'A']--;
		cnt['I'-'A']--;
		cnt['N'-'A']--;
		cnt['E'-'A']--;
	}
	sort(res.begin(),res.end());
	return res;
}


int main() {
    ifstream ifile;
    ofstream ofile;
    ifile.open("Input.txt");
    ofile.open("Output.txt");

    int CaseIdx,TotalCase;
    string line;
    getline(ifile,line);
    stringstream ss(line);
    ss>>TotalCase;

    for (CaseIdx = 1; CaseIdx<=TotalCase; CaseIdx++)
    {
//  begin of code
  //  1. prepare data for current test case
    	string A;
    	LL N;
    	vector<LL> nums;

		string line;
		{getline(ifile,line);stringstream ss(line);ss>>A;}



  //  2. data_pre_processing if possible. (significantly reduced time/space complextity

  //  3. data_processing to get the result

		//int res = fun(A,B,C);
		string res = fun(A);

  //  4. Output results;
		string caseResult="";
		caseResult = res;

    	cout<<"Case #"<<CaseIdx<<": "<<caseResult<<endl;
    	ofile<<"Case #"<<CaseIdx<<": "<<caseResult<<endl;

// end of code
    }


    ifile.close();
    ofile.close();
	return 0;
}

