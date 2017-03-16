#include<iostream>
#include<vector>
using namespace std;

int si(char c){
	if(c=='0') return 0;
	if(c=='1') return 1;
	if(c=='2') return 2;
	if(c=='3') return 3;
	if(c=='4') return 4;
	if(c=='5') return 5;
	if(c=='6') return 6;
	if(c=='7') return 7;
	if(c=='8') return 8;
	if(c=='9') return 9;
}

int main(){
	int t;cin>>t;
	for(int qq=1;qq<=t;qq++){
		int smax; cin>>smax;
		string s; cin>>s;
		int c=0,f=0;
		for(int i=0;i<s.size();i++){
			if(c<i) {f+=(i-c);c=i;}
			c+=si(s[i]);
		}
		cout<<"Case #"<<qq<<": "<<f<<endl;
	}
}
		
