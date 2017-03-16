#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

int dp[1000010];

int main() {
	freopen("counter_culture.in","r",stdin);
	freopen("counter_culture.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	dp[1]=1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int t=q.front(), c=dp[t];
		q.pop();
		if (t+1<1000010 && (dp[t+1]==-1 || dp[t+1]>c+1)) {
			dp[t+1]=c+1;
			q.push(t+1);
		}
		int rev=0;
		while (t>0) {
			rev=rev*10+(t%10);
			t/=10;
		}
		if (rev<1000010 && (dp[rev]==-1 || dp[rev]>c+1)) {
			dp[rev]=c+1;
			q.push(rev);
		}
	}
	
	int tc, nt=1;
	cin>>tc;
	while (tc--) {
		int n;
		cin>>n;
		cout<<"Case #"<<nt++<<": "<<dp[n]<<endl;
	}
}
