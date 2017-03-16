/**/
#include<bits/stdc++.h>
using namespace std;
/***********************************************/
/*      ____________
 *     /            \
 *    /  /\      /\  \
 *   /  /  \    /  \  \
 *   \                /
 *    \     \___/    /
 *     \____________/
 */
const long long mod = 1000000007;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("out.txt","w",stdout);
	freopen("A-large.in","r",stdin);
	int T,C = 1;
	cin>>T;
	while(T--){
		cout<<"Case #"<<C++<<": ";
		string s;
		cin>>s;
		string t;
		char cur = '\0';
		for(int i = 0; i < s.size();i++){
			if(s[i] >= cur){
				t = s[i] + t;
				cur = s[i];
			}else{
				t += s[i];
			}
		}
		cout<<t<<'\n';
	}
	return 0;
}
/**/
