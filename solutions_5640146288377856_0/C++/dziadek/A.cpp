#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define f first
#define s second

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;

int dp[25];
int r,c,w;

int go(int n){
	if(n < w) return 0;
	if(n == w) return w;
	if(dp[n] != -1) return dp[n];

	int res = n;

	FOR(i,1,n)
		res = min(res,max(1+go(n-i)+go(i-1),w+1));

	dp[n] = res;
	return res;
}

void testcase(){
	cin >> r >> c >> w;
	FOR(i,0,c) dp[i] = -1;
	cout << r*go(c);
}

int main(){
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;

	FOR(i,1,t){
		cout << "Case #" << i << ": ";
		testcase();
		cout << endl;
	}

	return 0;
}
