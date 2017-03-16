#include<bits/stdc++.h>
#define M 20
using namespace std;
set < string > s0 , s1;
vector < string > all0 , all1;
string x[M + 2] , y[M + 2];
int n , ans;
void solve(){
	ans = 0;
	all0.clear(); all1.clear();
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		cin>>x[i]>>y[i];
		all0.push_back(x[i]) ; all1.push_back(y[i]);
	}
	for(int mask = 0 ; mask < (1<<n) ; mask++){
		int cnt = 0;
		s0.clear(); s1.clear();
		for(int i = 0 ; i < n ; i++)	if(mask&1<<i){
			cnt++; s0.insert(x[i]) ; s1.insert(y[i]);
		}
		for(int i = 0 ; i < n ; i++){
			if(s0.find(all0[i]) == s0.end())	cnt = n;
			if(s1.find(all1[i]) == s1.end())	cnt = n;	
		}
		ans = max(ans , n - cnt);
	}
	printf("%d\n",ans);
}
main(){
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int tc;
	scanf("%d",&tc);
	for(int i = 1 ; i <= tc ; i++){
		printf("Case #%d: ",i);
		solve();
	}
}
