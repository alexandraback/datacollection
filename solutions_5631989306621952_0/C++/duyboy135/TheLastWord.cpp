#include<bits/stdc++.h>
#include<string>
using namespace std;
string s , t;
int T;
main(){
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	cin>>T;
	for(int tc = 1 ; tc <= T ; tc++){
		t = "";
		cin>>s;
		for(int i = 0 ; i < s.size() ; i++)	t = max(t + s[i] , s[i] + t);
		cout<<"Case #"<<tc<<": "<<t<<'\n';
	}
}
