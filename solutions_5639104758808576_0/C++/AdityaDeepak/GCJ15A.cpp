// adijimmy
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
int dp[1010];
int main(){
 freopen("A-small-attempt1.in","r",stdin);
 freopen("ans.txt","w",stdout);
 int t,n;
 string s;
 cin >> t;
 for(int cas=1;cas<=t;cas++){
	printf("Case #%d: ",cas);
	cin >> n >> s;
	int cnt = 0;
	vector<int> vec;
	for(int i=0;i<n+1;i++){
		vec.push_back(s[i]-'0');
	}
	int sz = vec.size();
	memset(dp,0,sizeof dp);
	dp[0] = vec[0];
	for(int i=1;i<sz;i++){
		dp[i] = dp[i-1]+vec[i];
	}
	int cnt1 = 0,cnt2 = 0;
   for(int i=0;i<sz;i++){
		if(cnt1 >= i) cnt1 += vec[i];
		else if(vec[i] != 0){
			cnt2 += (i-cnt1);
			cnt1 += (i+vec[i]-cnt1); // checking satisfiability
		}
	}
	cout << cnt2 << endl;
 }
 return 0;
}
