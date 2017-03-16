#include<iostream>
#include<string>
using namespace std;

int main(){
	int T;
	cin>>T;
	int ans=0;
	int K,C,S;
	for(int cs=1;cs<=T;++cs){
		cin>>K>>C>>S;
		cout<<"Case #"<<cs<<":";
		for(int i=1;i<=S;++i){
			cout<<" "<<i;
		}
		cout<<endl;
	}
	return 0;
}
