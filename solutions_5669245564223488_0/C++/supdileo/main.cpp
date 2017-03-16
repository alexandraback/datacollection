#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int fac[11] = {1,1,2,6,24,120,720,5040,40320,362880,3628800};
vector<string> sets;
vector<bool> vis;
int N;
ll mod = 1000000007;

int Valid(int n){
	vis.assign(27,false);
	char last = 0;
	for(int i=0;i<n;i++){
		string& str = sets[i];
		for(int j=0;j<str.size();j++){
			if(!vis[str[j]-'a']){
				vis[str[j]-'a'] = true;
			}else if(last!=str[j]){
				return 0;
			}
			last = str[j];
		}
	}
	return 1;
}

string shrink(const string& str){
	string ret;
	for(int i=0;i<str.size();i++){
		if(i==0||str[i]!=str[i-1])ret.push_back(str[i]);
	}
	return ret;
}

int main(){
	ifstream cin("B-small-attempt3.in");
	//ifstream cin("in.txt");
	ofstream cout("out");
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		sets.clear();
		ll ret = 0;
		cin>>N;
		string tmp;
		for(int i=0;i<N;i++){
			cin>>tmp;
			sets.push_back(tmp);
		}
		sort(sets.begin(),sets.end());
		for(int i=0;i<N;i++){
			sets[i] = shrink(sets[i]);
		}
		int dup=1,multi=1;
		for(int i=1;i<N;i++){
			if(sets[i]==sets[i-1])dup++;
			else{
				multi *= fac[dup];
				dup = 1;
			}
		}
		multi *= fac[dup];
		vector<string>::iterator it = unique(sets.begin(),sets.end());
		int newlen = distance(sets.begin(),it);
		sets.resize(newlen);

		do{
			ret += Valid(newlen);
		}while(next_permutation(sets.begin(),sets.end()));
		cout<<"Case #"<<t<<": "<<(ret*multi)%mod<<endl;
	}
	return 0;
}