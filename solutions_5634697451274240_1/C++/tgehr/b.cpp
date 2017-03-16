#include <bits/stdc++.h>
using namespace std;

int cnt;
void sort(string& s,int n,char t){
	if(n==0) return;
	if(s[n-1]==t){
		sort(s,n-1,t);
	}else{
		sort(s,n-1,'-'^'+'^t);
		cnt++;
	}
}

void solve(string& s){
	cnt=0;
	sort(s,s.size(),'+');
	cout<<cnt<<'\n';
}

int main(){
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		string s;
		cin>>s;
		cout<<"Case #"<<t<<": ";
		solve(s);
	}
}
