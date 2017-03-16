#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main(){
	int T,cnt=0;
	cin>>T;
	while(T--){
		string s,t;
		cin>>s;
		int l=s.length();
		t="";
		for(int i=0; i<l; ++i)
			if (i==0) t=t+s[i];
			else if (t[0]<=s[i]) t=s[i]+t;
			else t=t+s[i];
		cnt++;
		cout<<"Case #"<<cnt<<": "<<t<<endl;
	}
	return 0;
}
