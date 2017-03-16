#include <bits/stdc++.h>

#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOE(i, s, t) for (int i = s; i <= t; i++)

using namespace std;

string ret ;

void solve(){
	string x;
	cin >> x;
		
	ret = x[0];
	FOR(i, 1, x.length()){
		if (x[i] >= ret[0]) ret = x[i] + ret;
		else ret = ret + x[i];
	}	
	
	cout << ret << endl;
	
}

int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int tc; scanf("%d", &tc);
	FOE(i, 1, tc){
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
