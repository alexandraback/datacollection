#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1100;
int f[MAXN];
int N;
bool isvalid(string s){
	if(s.size() == 2) return 1;
	for(int i=1; i<s.size()-1; ++i){
		if(f[s[i]-'0']!=s[i+1]-'0'){
			if(f[s[i]-'0']!=s[i-1]-'0'){
				return 0;
			}
		}
	}
	return 1;
}
bool make(int cur, int mask, string s){
	if(!cur){
//		cout << s << endl;
		for(int i=1; i<s.size()-1; ++i){
			if(f[s[i]-'0']!=s[i+1]-'0'){
				if(f[s[i]-'0']!=s[i-1]-'0'){
					return 0;
				}
			}
		}
		if(f[s[0]-'0']!=s[1]-'0' && f[s[0]-'0']!=s[s.size()-1]-'0') return 0;
		if(f[s[s.size() - 1]-'0']!=s[s.size() - 2]-'0' && s[0]-'0'!=f[s[s.size()-1]-'0']) return 0;
		return 1;

	}
	else{
		int ret = 0;
		for(int i=1; i<=N; ++i){
			if(mask & (1<<i)) continue;
			char x = '0' + i;
			if(isvalid(s+x)) ret = max(ret, (int)make(cur-1,mask|1<<i,s+x));
			if(ret) break;
		}
		return ret;
	}
}
bool get(int pos){
	string temp = "";
	return make(pos,0,temp);
}
int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small.out","w",stdout);
	int t, c = 0;
	cin >> t;
	while(t--){
		cin >> N;
		cout << "Case #" << ++c <<": ";
		int ans = 0;
		for(int i=1; i<=N; ++i) cin >> f[i];
		for(int i=N; i>1; --i){
			if(get(i)){
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
}
