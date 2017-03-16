#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main() {
	int T;
	scanf("%d", &T);
	char s[10010];
	for(int caso=1 ; caso<=T ; caso++) {
		scanf("%s", s);
		int len = strlen(s);
		string ans = "";
		ans = ans + s[0];
		for(int i=1 ; i<len ; i++) {
			string tmp = "";
			tmp = tmp + s[i];
			if( s[i] >= ans[0] ) ans = tmp + ans;
			else ans = ans + tmp;
		}
		cout<<"Case #"<<caso<<": "<<ans<<endl;
	}
	return 0;
}