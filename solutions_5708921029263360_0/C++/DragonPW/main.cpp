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

int fun(LL A, LL B, LL C, LL K,vector<string> &res){

for (int i=1;i<=A;i++)
	for (int j=1;j<=B;j++)
		for (int l=1;l<=C && l<=K;l++){
			res.push_back(to_string(i)+" "+to_string(j)+" "+to_string((i+j+l)%C+1));
		}

	return min(A*B*C,A*B*K);
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
    	LL A,B,C,K;
		string line;
		{getline(ifile,line);stringstream ss(line);ss>>A>>B>>C>>K;}


  //  2. data_pre_processing if possible. (significantly reduced time/space complextity

  //  3. data_processing to get the result
		vector<string> resv;
		int res = fun(A,B,C,K,resv);
//		int res = funv(nums);

  //  4. Output results;
		string caseResult="";
		caseResult += to_string(res);
//        for (auto &x:res) caseResult += to_string(x)+" ";
    	cout<<"Case #"<<CaseIdx<<": "<<caseResult<<endl;
    	for (auto &x:resv) cout<<x<<endl;
    	ofile<<"Case #"<<CaseIdx<<": "<<caseResult<<endl;
    	for (auto &x:resv) ofile<<x<<endl;

// end of code
    }


    ifile.close();
    ofile.close();
	return 0;
}

