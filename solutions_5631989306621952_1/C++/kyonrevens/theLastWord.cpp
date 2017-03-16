#include <bits/stdc++.h>
using namespace std;

int T, TC = 1;
char S[1005], d;
void solve(){
	string ans;
	ans.push_back(S[0]);
	int len = strlen(S);
	for(int i = 1; i < len; i++){
		string tmp;
		tmp.push_back(S[i]);
		if(tmp+ans >= ans+tmp) ans = tmp+ans;
		else ans = ans+tmp;
	}
	cout << ans << endl;
}
int main(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	scanf("%d%c", &T, &d);
	while(T--){
		gets(S);
		printf("Case #%d: ", TC++);
		solve();
	}
	return 0;
}
