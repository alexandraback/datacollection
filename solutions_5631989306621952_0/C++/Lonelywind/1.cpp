#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
	int tt;
	char s[1005];
	cin>>tt;
	for (int cs=1;cs<=tt;cs++){
		printf("Case #%d: ",cs);
		scanf("%s",s);
		int l=strlen(s);
		string s1="",s2="",ans="";
		for (int i=0;i<l;i++){
			s1=ans+s[i];
			s2=s[i]+ans;
			if (s1>s2) ans=s1;
			else ans=s2;
		}

		cout<< ans<<endl;
	}

	return 0;
}