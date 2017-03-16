#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define FORI(A,B,C) for(int I=(A);I<=(B); I++)
#define FORLL(A,B,C) for(LL I=(A);I<=(B); I++)
#define VLL vector<LL>
#define VVLL vector<vector<LL>>
#define VI vector<int>
#define VVI vector<vector<int>>

#define showv(A) for(auto &x:A){cout<<x<<" ";}cout<<endl;

vector<string> fun(int B, LL M){
	vector<string> res;
	LL maxV=1;
	maxV<<=(B-2);
	if (M>maxV) {
		res.push_back("IMPOSSIBLE");
		return res;
	}else{
		res.push_back("POSSIBLE");
	}
	for (int i=0;i<B;i++){
		res.push_back(string (B,'0'));
	}
	for (int i=1;i<B-1;i++){
		for (int j=0;j<i;j++) res[B-i][B-1-j]='1';
	}
	if (M==maxV){
		for (int i=1;i<B;i++){
			res[1][i]='1';
		}
	}else{
		int idx=1;
		while (M){
			if (M&1) res[1][B-1-idx]='1';
			idx++;
			M>>=1;
		}
	}
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
    	int B,M;


		string line;
		{getline(ifile,line);stringstream ss(line);ss>>B>>M;}


  //  2. data_pre_processing if possible. (significantly reduced time/space complextity

  //  3. data_processing to get the result
		vector<string> res = fun(B,M);
//		int res = funv(nums);

  //  4. Output results;

    	cout<<"Case #"<<CaseIdx<<": ";
    	ofile<<"Case #"<<CaseIdx<<": ";
    	for (auto &x:res) {
    		cout<<x<<endl;
    		ofile<<x<<endl;
    	}

// end of code
    }


    ifile.close();
    ofile.close();
	return 0;
}

