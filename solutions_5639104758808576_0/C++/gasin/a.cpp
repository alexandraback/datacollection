#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int cnt[2000];

void solve(){
	int s;
	int ans = 0;
	scanf("%d",&s);
	s++;
	rep(i,2000) cnt[i] = 0;
	string str;
	cin >> str;
	rep(i,s) cnt[i] = str[i]-'0';
	int sum = 0;
	rep(i,s){
		if(sum < i){
			ans += i-sum;
			sum = i;
		}
		sum += cnt[i];
	}
	printf("%d\n",ans);
}

int main(){
	int t;
	scanf("%d",&t);
	rep(i,t){
		printf("Case #%d: ",i+1);
		solve();
	}
}