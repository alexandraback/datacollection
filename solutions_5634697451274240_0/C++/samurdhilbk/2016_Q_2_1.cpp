#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

string flip(string s){
	reverse(s.begin(),s.end());
	for(int k=0;k<s.size();k++){
		if(s[k]=='-') s[k]='+';
		else s[k]='-';
	}
	return s;
}

ll solve(string s){
	if(s.size()==1){
		if(s[0]=='+') return 0;
		else return 1;
	} 
	if(s[s.size()-1]=='+') return solve(s.substr(0,s.size()-1));
	else{
		ll mn=LLONG_MAX;
		if(s[0]=='-') mn=min(mn,1+solve(flip(s).substr(0,s.size()-1)));
		for(int i=0;i<s.size()-1;i++){
			if(s[i]=='+'){
				string temp=flip(s.substr(0,i+1))+s.substr(i+1,s.size()-i-1);
				mn=min(mn,2+solve(flip(temp).substr(0,temp.size()-1)));
			}
		}
		return mn;
	}
} 

int main(){

	ios_base::sync_with_stdio(false);
	string s;
	getline(cin,s);
	int t;
	stringstream(s)>>t;
	for(int i=0;i<t;i++){
		getline(cin,s);
		map<string,ll> mp;
		vector<string> vec;
		printf("Case #%d: %lld\n",i+1,solve(s));
	}
}