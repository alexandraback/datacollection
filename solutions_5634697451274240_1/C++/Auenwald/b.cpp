#include <bits/stdc++.h>

using namespace std;

#define INTMAX 0x7FFFFFFF
#define INTMIN -0x80000000
#define LONGMAX 0x7FFFFFFFFFFFFFFF
#define LONGMIN -0x8000000000000000

int main(){
	ios_base::sync_with_stdio(false);
	
	int T;
	cin>>T;
	for(int case_nr=1; case_nr<=T; case_nr++){
		string s;
		cin>>s;
		int ch = 0;
		for(int i=1; i<s.length(); i++){
			if(s[i]!=s[i-1])
				ch++;
		}
		if(s[s.length()-1]=='-')
			ch++;
		cout<<"Case #"<<case_nr<<": "<<ch;
		cout<<"\n";
	}
}