#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int M;

int check(string s, string l){
	int L = l.length();
	int res = 0;
	for(int i=0; i<s.length()-L+1; i++){
		if(l.compare(s.substr(i,L))==0) res++;
	}
	return res;
}

int cons(string key, string s, string l, int S){
	if(s.length()==S){
		int n = check(s,l);
		M = max(M,n);
		return n;
		//return 0;
	}
	int res=0;


	for(int i=0; i<key.length(); i++){
		s.push_back(key[i]);
		res+=cons(key,s,l,S);
		s.pop_back();
	}
	return res;
}

void solve(){
	int K,L,S;
	cin>>K>>L>>S;
	string key,expect;
	cin>>key>>expect;
	//cout<<key<<expect;
	int res = cons(key,"",expect,S);
	double expe = (double)res/(double)pow(K,S);
	//cout<<pow(K,S);
	cout<<fixed;
	cout<<setprecision(7)<<(double)M-expe<<endl;
	return;
}

int main(){
	int T;
	freopen("B-small-attempt1.in","r",stdin);
	freopen("outs1","w",stdout);
	cin>>T;
	for(int t=0; t<T; t++){
		M=0;
		printf("Case #%d: ",t+1);
		solve();
	}
	return 0;
}