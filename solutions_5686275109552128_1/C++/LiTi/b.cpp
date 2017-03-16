/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000 + 100; 
int a[maxN];
int dp[maxN][maxN];

int calc() { 
	int n;
	cin >> n; 
	for( int i = 0 ; i < n;  i++) 
		cin >> a[i];

	int ans = maxN ; 
	for( int k = 1 ; k < maxN ; k++ ) { 
		int tmp = 0 ; 
		for( int i = 0 ; i < n ; i++ ) 
			tmp += ( a[i] + k - 1 ) / k - 1 ; 
		ans = min( k + tmp , ans ) ; 
	}

	return ans;
}

int main() { 
	int t;
	cin >> t;
	for( int i = 0 ; i < t; i++ ) 
		cout << "Case #" << i+1 << ": " << calc() << endl;
}
