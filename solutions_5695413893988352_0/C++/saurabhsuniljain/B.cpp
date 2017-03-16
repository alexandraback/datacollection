#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int testcase;

pair <string, string> ss(string c, string J){
	int len = c.size();
	pair <string, string> pans;
	pair <string, string> tans;
	int diff = 1000;
	int tdiff;
	bool not_changed = true;
	for(int i = 0; i<len; i++){
		if(c[i]=='?'){
			not_changed = false;
			for(char j = '0'; j<='9'; j++){
				c[i] = j;
				tans = ss(c,J);
				tdiff = abs(stoi(tans.first)-stoi(tans.second));
				if(tdiff<diff){
					pans = tans;
					diff = tdiff;
				} else if(tdiff == diff){
					if(stoi(tans.first)<stoi(pans.first)){
						pans = tans;
					} else if(stoi(tans.first)==stoi(pans.first)){
						if(stoi(tans.second)<stoi(pans.second)){
							pans = tans;
						}
					}
				}
			}
		}
	}
	for(int i = 0; i<len; i++){
		if(J[i]=='?'){
			not_changed = false;
			for(char j = '0'; j<='9'; j++){
				J[i] = j;
				tans = ss(c,J);
				tdiff = abs(stoi(tans.first)-stoi(tans.second));
				if(tdiff<diff){
					pans = tans;
					diff = tdiff;
				} else if(tdiff == diff){
					if(stoi(tans.first)<stoi(pans.first)){
						pans = tans;
					} else if(stoi(tans.first)==stoi(pans.first)){
						if(stoi(tans.second)<stoi(pans.second)){
							pans = tans;
						}
					}
				}
			}
		}
	}
	if(not_changed) pans = make_pair(c,J);
	return pans;
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