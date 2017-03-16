#include <bits/stdc++.h>

using namespace std;
#define ll long long



vector<ll> fun(ll K, ll C, ll S){
	vector<ll> res;
	if (C*S<K) return res;
    for (ll i=0;i*C<K;i++){
    	ll idx=0;
    	for (ll j=0;j<C & i*C+j<K;j++){
    		idx*=K;
    		idx+=i*C+j;
    	}
    	res.push_back(idx+1);
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
		vector<ll> res=fun(K,C,S);
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

