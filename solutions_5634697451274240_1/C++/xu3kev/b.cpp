#include<iostream>
#include<string>
using namespace std;

int main(){
	int T;
	cin>>T;
	int ans=0;
	string s;
	for(int cs=1;cs<=T;++cs){


		cin>>s;
		
		int count = 0;
		for(int i=1;i<s.size();++i){
			if(s[i]!=s[i-1]){
				++count;
			}
		}
		if(s[s.size()-1]=='-'){
			++count;
		}
		ans = count;
		cout<<"Case #"<<cs<<": "<<ans<<endl;
	}
	return 0;
}
