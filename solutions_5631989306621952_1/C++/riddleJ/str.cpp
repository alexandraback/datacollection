#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	string str;
	string ans;
	char st,end;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>str;
		st=str[0];
		end=str[0];
		ans=str[0];
		
		for(int j=1;j<str.length();j++){
			if(str[j]>=st){
				//strcat(str[j],ans);
				ans=str[j]+ans;
				st=str[j];
			}else{
				ans=ans+str[j];
				end=str[j];
			}
		}

		cout<<"Case #"<<(i+1)<<": "<<ans<<endl;
	}
}