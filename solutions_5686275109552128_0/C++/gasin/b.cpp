#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

void solve(){
	int ans = 10000, d;
	int p[2000];
	
	scanf("%d",&d);
	rep(i,d) scanf("%d",p+i);
	
	for(int i = 1; i <= 1000; i++){
		int sum = i;
		rep(j,d){
			if(p[j] <= i) continue;
			int q = p[j]/i;
			if(p[j]%i != 0) q++;
			sum += q-1;
		}
		ans = min(sum,ans);
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