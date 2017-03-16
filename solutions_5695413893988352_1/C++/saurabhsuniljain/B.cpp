#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int testcase;

pair <string, string> ss(string c, string j){
	int len = c.size();
	for(int i = len-1; i>=0 ;i--){
		if(c[i]=='?'){
			if(j[i]=='?'){
				c[i] = '0';
				j[i] = '0';
			}else{
				c[i] = j[i];
			}
		}else{
			if(j[i]=='?'){
				j[i] = c[i];
			}
		}
	}
	return make_pair(c,j);
}

void solve(){
	testcase++;
	pair <string, string> ans;
	string c,j;
	cin>>c>>j;
	ans = ss(c,j);
	cout<<"Case #"<<testcase<<": "<<ans.first<<" "<<ans.second<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}