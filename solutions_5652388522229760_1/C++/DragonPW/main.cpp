#include <bits/stdc++.h>

using namespace std;
#define ll long long

long long countTime(ll N){
	if (N==0) return -1;
	N = abs(N);
	ll num;
	set<int> digits;
	ll cnt=1;
	int d=0;
	while (cnt){
		num = cnt*N;
		while(num){
			d=num%10;
			num=num/10;
			digits.insert(d);
			if (digits.size()==10) return cnt*N;
		}
		cnt++;
	}
	return -1;
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
    	ll N;
		string line;
		{
			getline(ifile,line);
			stringstream ss(line);
			ss>>N;
		}
  //  2. data_pre_processing if possible. (significantly reduced time/space complextity

		ll res = countTime(N);


  //  3. data_processing to get the result


  //  4. Output results;
		string caseResult;
		if (res==-1)
			caseResult = "INSOMNIA";
		else
			caseResult=to_string(res);


    	cout<<"Case #"<<CaseIdx<<": "<<caseResult<<endl;
    	ofile<<"Case #"<<CaseIdx<<": "<<caseResult<<endl;

// end of code
    }


    ifile.close();
    ofile.close();
	return 0;
}

