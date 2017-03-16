#include <iostream>

using namespace std;

int testcase = 0;

void solve(){
	testcase++;
	string ans = "",s;
	cin>>s;
	int len = s.size();
	ans += s[0];
	for(int i = 1; i<len; i++){
		if(s[i]>=ans[0]) ans = s[i] + ans;
		else ans += s[i];
	}
	cout<<"Case #"<<testcase<<": "<<ans<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}