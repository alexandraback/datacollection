#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string rec(string s){
	if(s.size()==0)
		return s;
	int max_idx=0;
	for(int i=1;i<s.size();++i){
		if(s[i]>=s[max_idx])
			max_idx = i;
	}
	return s[max_idx]+rec(s.substr(0,max_idx))+(s.substr(max_idx+1,s.size()-max_idx));
}
int main(){
	int TT;
	cin>>TT;
	int ans=0;
	string s;
	for(int T=1;T<=TT;++T){
		cin>>s;
		
		cout<<"Case #"<<T<<": "<<rec(s)<<"\n";


	}
	return 0;
}

