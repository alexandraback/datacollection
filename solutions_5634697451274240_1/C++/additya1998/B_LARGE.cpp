#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("B-large.in","r",stdin);
	freopen("Bout.out","w",stdout);
	int t;
	cin >> t;
	int a[1100];
	int c=0;
	while(t--){
		++c;
		int ans = 0;
		string s;
		cin >> s;
		for(int i=0; i<s.size(); ++i){
			if(s[i] == '+') a[i+1] = 1;
			else a[i+1] = 0;
		}
		for(int i=s.size(); i>0; --i){
			if(a[i]) continue;
			else{
				++ans;
				for(int j=i; j>0; --j) a[j]^=1;
			}
		}
		cout << "Case #" << c << ": " << ans << endl;
	}
}

