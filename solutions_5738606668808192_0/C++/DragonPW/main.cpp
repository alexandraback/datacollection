#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll str2Base(string s, ll base){
	ll res=0;
	for (auto &x:s){
		res*=base;
		if (x=='1'){
			res+=1;
		}
	}
	return res;
}

string int2bin(ll x){
	string res;
	while(x){
		if (x&1){
			res+='1';
		}else{
			res+='0';
		}
		x>>=1;
	}
	reverse(res.begin(),res.end());
	return res;
}

ll isPrime(ll x){
	if (x<2) return 0;
	for (ll i=2;i<sqrt(x);i++){
		if (x%i==0) return i;
	}
	return -1;
}

vector<string> fun(int N,int J){
	vector<string> res;

//	vector<int> isPrime(MaxNum+1,1);
//	for (ll i=2;i<MaxNum+1;i++){
//		ll j=2;
//		if (isPrime[i]==1){
//			while (j*i<=MaxNum){
//				isPrime[i*j]=i;
//				j++;
//			}
//		}
//	}

	unsigned int curNum=1;
	curNum<<=(N-1);
	curNum++;
	for (int i=0;i<J;){
		string curNumStr = int2bin(curNum);
		string curRes="";
		curRes += curNumStr+" ";
		int base;
		for (base=2;base<=10;base++){
			ll temp = str2Base(curNumStr,base);
			ll ip = isPrime(temp);
			if (ip==-1) break;
			else{
			    curRes += to_string(ip)+" ";
			}
		}
		if (base==11) {
			res.push_back(curRes);
			i++;
		}
		curNum+=2;
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
    	ll N,J;
		string line;

		{
			getline(ifile,line);
			stringstream ss(line);
			ss>>N;
			ss>>J;
		}

  //  2. data_pre_processing if possible. (significantly reduced time/space complextity


  //  3. data_processing to get the result


  //  4. Output results;
		vector<string> caseResult=fun(N,J);


    	cout<<"Case #"<<CaseIdx<<":"<<endl;
    	for (auto &x:caseResult){
    		cout<<x<<endl;
    	}

    	ofile<<"Case #"<<CaseIdx<<":"<<endl;
		for (auto &x:caseResult){
			ofile<<x<<endl;
		}


// end of code
    }


    ifile.close();
    ofile.close();
	return 0;
}

