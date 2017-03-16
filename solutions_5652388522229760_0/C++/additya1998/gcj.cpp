#include<bits/stdc++.h>
using namespace std;
bool get(int cur, int a[]){
	while(cur){
		a[cur%10] = 1;
		cur/=10;
	}
	for(int i=0; i<10; ++i) if(!a[i]) return 0;
	return 1;
}
int ans[1100000];
int main(){
	ans[0] = -1;
	for(int i=1; i<=1000001; ++i){
		int a[10];
		memset(a,0,sizeof a);
		int cur = i;
		while(!get(cur,a)){
			cur+=i;
		}
		ans[i] = cur;
	}
	freopen("A-small-attempt0.in","r",stdin);
	freopen("outA.out","w",stdout);
	int t;
	cin >> t;
	int cnt = 1;
	while(t--){
		int x;
		cin >> x;
		if(!x) cout << "Case #" << cnt++ << ": " << "INSOMNIA" << endl;
		else cout << "Case #" << cnt++ << ": " << ans[x] << endl;
//		cout << ans[x] << endl;
	}
}
