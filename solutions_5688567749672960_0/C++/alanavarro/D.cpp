#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define se second
#define fi first

using namespace std;
typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
const int MAX = 1e6+6;

int dp[MAX];

int rev( int k){
	int r = 0;
	while( k > 0 ){
		r *= 10;
		r += k%10;
		k /= 10;
	}
	return r;
}

int main(){
	
	freopen("a.in","r", stdin);
	freopen("a.out","w", stdout);
	
	int t;
	cin >> t;
	int n, ntc = 1, cur, x;
	while( t-- ){
		memset( dp, 0 , sizeof(dp));
		cin >> n;
		queue < int > q;
		q.push(1);
		dp[1] = 1;
		while( !q.empty() ){
			cur = q.front();
			q.pop();
			if( cur == n ) break;
			
			if( dp[cur+1] == 0 ){
				dp[cur+1] = dp[cur] + 1;
				q.push(cur+1);
			}
			x = rev(cur);
			//cout << cur << " " << x << endl;
			if( dp[x] == 0 && x > cur ){
				dp[x] = dp[cur]+1;
				q.push(x);
			}
			
		}
		printf("Case #%d: %d\n", ntc, dp[n] );
		ntc++;
	}

	return 0;
}
