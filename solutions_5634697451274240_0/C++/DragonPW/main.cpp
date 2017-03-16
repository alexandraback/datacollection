#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll fun(string s){
	if (s.empty()) return 0;
	ll cnt = 0;
	for (int i=1;i<s.size();i++){
		if (s[i]!=s[i-1]) cnt++;
	}
	if (s.back()=='-') cnt++;
	return cnt;
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
    	string str;
		string line;

		{
			getline(ifile,line);
			stringstream ss(line);
			ss>>str;

		}

  //  2. data_pre_processing if possible. (significantly reduced time/space complextity


  //  3. data_processing to get the result


  //  4. Output results;
		string caseResult=to_string(fun(str));


    	cout<<"Case #"<<CaseIdx<<": "<<caseResult<<endl;
    	ofile<<"Case #"<<CaseIdx<<": "<<caseResult<<endl;

// end of code
    }


    ifile.close();
    ofile.close();
	return 0;
}

