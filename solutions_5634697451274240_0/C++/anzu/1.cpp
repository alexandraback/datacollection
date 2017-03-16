#include<iostream>
#include<set>
#include<fstream>

using namespace std;

set<int >a ; 

void operate(long long n){
	while(n){
		a.insert(n%10);
		n/=10;
	}
}

int main(){
	//ifstream cin("B-small-attempt0.in");
	//ofstream cout("1.txt");
	long long n,t,q;
	cin>>t;
	cin.get();
	string s;
	int res=0;
	for(int i=1;i<=t;++i){
		cin>>s;
		cin.get();
		cout<<"Case #"<<i<<": ";
		//res=(s[0]=='-');
		res=0;
		for(int j=0;j<s.length()-1;++j)
			res+=(s[j]!=s[j+1]);
		if (s[s.length()-1]!='+')
			++res;
		cout<<res<<'\n';
	}
}