#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

string s;

void solve(){
	int res = 0;
	if(s[s.length()-1]=='-')	res = 1;
	for(int i=1;i<s.length();i++)	if(s[i]!=s[i-1])	res++;
	cout<<res<<'\n';
}


int main(){
	ios_base::sync_with_stdio(0);	cin.tie();
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;	cin>>t;
	for(int tt=1;tt<=t;tt++){
		cin>>s;
		cout<<"case #"<<tt<<": ";
		solve();
	}
}