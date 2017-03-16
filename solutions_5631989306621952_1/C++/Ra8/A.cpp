#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
string S;
string solve(){
	string ans="";
	for(int i=0;i<S.length();i++){
		string tmp=" ";
		tmp[0]=S[i];
		string s1=ans+tmp;
		string s2=tmp+ans;
		if(s1>s2){
			ans = s1;
		} else {
			ans = s2;
		}
	}
	return ans;
}
int main(int argc, char const *argv[]){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		cin >> S;
		string ans= solve();
		printf("Case #%d: ",t+1);
		cout << ans << endl;
	}
	return 0;
}