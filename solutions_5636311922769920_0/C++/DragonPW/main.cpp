#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> fun(int K, int C, int S){
	vector<int> res;
    for (int i=1;i<=K;i++)
	res.push_back(i);
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
    	ll K,C,S;
		string line;

		{
			getline(ifile,line);
			stringstream ss(line);
			ss>>K>>C>>S;
		}

  //  2. data_pre_processing if possible. (significantly reduced time/space complextity


  //  3. data_processing to get the result


  //  4. Output results;
		vector<int> res=fun(K,C,S);
		string caseResult="";
		if (res.empty()) caseResult="IMPOSSIBLE";
		else {
			for(auto&x:res){
				caseResult+=to_string(x)+" ";
			}
			caseResult.pop_back();
		}

    	cout<<"Case #"<<CaseIdx<<": "<<caseResult<<endl;
    	ofile<<"Case #"<<CaseIdx<<": "<<caseResult<<endl;

// end of code
    }


    ifile.close();
    ofile.close();
	return 0;
}

