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
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
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

const int MAX = 1000005;

int dp[MAX], N;

int rev(int x){
	VI v;

	while(x){
		v.PB(x % 10);
		x /= 10;
	}

	int value = 0;
	for(int i = 0; i < v.size(); ++i){
		value *= 10;
		value += v[i];
	}

	return value;
}

void testcase(){
	int N;
	cin >> N;

	dp[N] = 1;

	FORD(n,N-1,1){
		dp[n] = dp[n+1] + 1;
		if(rev(n) > n && rev(n) <= N) dp[n] = min(dp[n], dp[rev(n)] + 1);
	}

	cout << dp[1];
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
