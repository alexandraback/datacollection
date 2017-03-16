#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cassert>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

vector<string> allPermsOf(const string&, int S);

int countSubString(string S, string sub);

vector<int> allSubStringCount(vector<string> strings, string sub);

int main(){
/*	cout<<"test ABABA dengan ABA: "<<countSubString("ABABA", "ABA")<<endl;
	cout<<"test WOLOLO dengan LOL: "<<countSubString("WOLOLO", "LOL")<<endl;
	cout<<"test WOLOLO dengan ABA: "<<countSubString("WOLOLO", "ABA")<<endl;
	cout<<"test WOLOLO dengan O: "<<countSubString("WOLOLO", "O")<<endl;*/

/*	cout<<"test all perms of MONKEY,2: "<<endl;
	vector<string> ppp = allPermsOf("MONKEY", 2);
	vector<int> counts = allSubStringCount(ppp,"O");
	for (int i=0;i<ppp.size();i++){
		cout<<ppp[i]<<" , "<< counts[i]<<endl;
	}*/
	cout.precision(9);
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		cout<<"Case #"<<i<<": ";
		int K,L,S;
		cin >> K >> L >> S;
//		cout << " K" << K <<" L" <<L << " S" <<S <<endl;
		string keys, substring;
		cin >> keys >> substring;
//		cout << " keys" << keys << " substring" << substring <<endl;
		vector<int> semuaKemungkinan = allSubStringCount(allPermsOf(keys,S),substring);
//		cout << " numBananasBrought" << *std::max_element(semuaKemungkinan.begin(),semuaKemungkinan.end()) << endl;
//		cout << " expectedGiven" << ((double) std::accumulate(semuaKemungkinan.begin(),semuaKemungkinan.end(),0))/semuaKemungkinan.size()<<endl;
		int max = *std::max_element(semuaKemungkinan.begin(),semuaKemungkinan.end());
		double expected = ((double) std::accumulate(semuaKemungkinan.begin(),semuaKemungkinan.end(),0))/semuaKemungkinan.size();
		cout << max - expected;
		cout<<endl;
	}	

	
	return 0;
}

int countSubString(string S, string sub){
	string::iterator it = S.begin();
	int count = 0;
	while (it!=S.end()){
		it = std::search(it,S.end(),sub.begin(),sub.end());
		if (it!=S.end()){
			count++;
			it++;
		}
	}
	return count;
}

vector<string> allPermsOf(const string& keystr, int S){
	assert(S>=1);
	if (S==1){
		vector<string> retval;
		for (int i=0;i<keystr.length();i++){
			retval.push_back(string(1,keystr.at(i)));
		}
		return retval;
	}else{
		vector<string> retval;
		vector<string> tambahdari = allPermsOf(keystr,S-1);
		for (int i=0;i<tambahdari.size();i++){
			for (int j=0;j<keystr.length();j++){
				retval.push_back(tambahdari[i] + keystr.at(j));
			}
		}
		return retval;
	}
}

vector<int> allSubStringCount(vector<string> strings, string sub){
	vector<int> retval(strings.size());
	for (int i=0;i<strings.size();i++){
		retval[i]=countSubString(strings[i],sub);
	}
	return retval;
}
