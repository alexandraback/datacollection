#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int Q;
string s;
int main(){
	freopen("i.txt","r",stdin);
	cin>>Q;
	for (int testcase=1;Q--;testcase++){
		cin>>s;
		int ans=0;
		int pre=0;
		for (int i=0;i<=s.size();i++){
			if (i==s.size() || i>0 && s[i]!=s[i-1]){
				pre++;
				if (s[i-1]=='-'){
					ans++;
					if (pre!=1)
						ans++;
				}
			}
		}
		cout<<"Case #"<<testcase<<": "<<ans<<endl;
	}
	return 0;
}
