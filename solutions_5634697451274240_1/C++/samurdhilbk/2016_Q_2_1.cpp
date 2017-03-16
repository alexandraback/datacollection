#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

map<string,ll> mp_p;
map<string,ll> mp_m;

string flip(string s){
	reverse(s.begin(),s.end());
	for(int k=0;k<s.size();k++){
		if(s[k]=='-') s[k]='+';
		else s[k]='-';
	}
	return s;
}

ll solve_p(map<string,ll> &mp_p,map<string,ll> &mp_m,string s);

ll solve_m(map<string,ll> &mp_p,map<string,ll> &mp_m,string s){
	if(mp_m.find(s)!=mp_m.end()) return mp_m[s];
 	if(s.size()==1){
		if(s[0]=='-') return 0;
		else return 1;
	} 
	if(s[s.size()-1]=='-'){
		ll ret=solve_m(mp_p,mp_m,s.substr(0,s.size()-1));
		mp_m[s]=ret;
		return ret;
	} 
	else{
		ll ret=solve_p(mp_p,mp_m,s.substr(0,s.size()-1));
		mp_p[s]=ret;
		return 1+ret;
	}
}

ll solve_p(map<string,ll> &mp_p,map<string,ll> &mp_m,string s){
	if(mp_p.find(s)!=mp_p.end()) return mp_p[s];
 	if(s.size()==1){
		if(s[0]=='+') return 0;
		else return 1;
	} 
	if(s[s.size()-1]=='+'){
		ll ret=solve_p(mp_p,mp_m,s.substr(0,s.size()-1));
		mp_p[s]=ret;
		return ret;
	} 
	else{
		ll ret=solve_m(mp_p,mp_m,s.substr(0,s.size()-1));
		mp_m[s]=ret;
		return 1+ret;
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
		printf("Case #%d: %lld\n",i+1,solve_p(mp_p,mp_m,s));
	}
}

