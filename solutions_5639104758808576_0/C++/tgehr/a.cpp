#include <iostream>
#include <string>
using namespace std;

int main(){
	int T,n;
	cin>>T;
	string s;
	for(int tt=1;tt<=T;tt++){
		cin>>n;
		cin>>s;
		int r=0,cur=0;
		for(int i=0;i<(int)s.size();i++){
			r=max(r,i-cur);
			cur+=s[i]-'0';
		}
		cout<<"Case #"<<tt<<": "<<r<<'\n';
	}
}
