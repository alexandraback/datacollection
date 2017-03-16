#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define MAX 1000009

int dp[MAX];

int reverse(int n){
	vector<int>dig;
	while(n){
		dig.push_back(n%10);
		n/=10;
	}
	for(int i=0;i<dig.size();i++){
		n*=10;
		n+=dig[i];
	}
	return n;
}

int main(){
	set<pair<int,int>>st;
	for(int i=0;i<MAX;i++){
		dp[i]=MAX;
		st.insert({MAX,i});
	}
	st.erase({MAX,1});
	st.insert({1,1});
	dp[1]=1;
	while(!st.empty()){
		pair<int,int>cur=*(st.begin());
		st.erase(st.begin());
		if(cur.second+1<MAX&&cur.first+1<dp[cur.second+1]){
			st.erase({dp[cur.second+1],cur.second+1});
			dp[cur.second+1]=cur.first+1;
			st.insert({dp[cur.second+1],cur.second+1});
		}
		int rev=reverse(cur.second);
		if(rev<MAX&&cur.first+1<dp[rev]){
			st.erase({dp[rev],rev});
			dp[rev]=cur.first+1;
			st.insert({dp[rev],rev});
		}
	}

	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		int n;
		scanf("%d",&n);
		printf("Case #%d: %d\n",tc,dp[n]);
	}
}
