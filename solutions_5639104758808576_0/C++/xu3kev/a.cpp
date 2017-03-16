#include<iostream>
#include<string>
using namespace std;
int main(){
	int T;
	cin>>T;
	int l;
	string s;
	for(int cs=1;cs<=T;++cs){

		cin>>l;
		cin>>s;
		int ans=0;
		int tot=0;
		for(int i=0;i<=l;++i){
			int tmp=s[i]-'0';
			if(i>tot){
				ans+=i-tot;
				tot=i;
			}
			tot+=tmp;
		}

		cout<<"Case #"<<cs<<": "<<ans<<endl;;
	}
	return 0;
}
