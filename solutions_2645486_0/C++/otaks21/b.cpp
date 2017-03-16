#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;
ll E, R, N, v[10], x[10], ans = 0;

void solve(ll e, int k, ll sum){
	if( e < 0 ) return;
	if( E < e ) e = E;
	
	if( k == N ){
		ans = max(ans, sum);
	}else{
		for(int i = 0; i <= e; i++){
			solve(e - i + R, k + 1, sum + i * v[k]);
		}
	}
}

int main(){
	int T;
	cin >> T;
	for(int t_ = 1; t_ <= T; t_++ ){
		ans = 0;
		cin >> E >> R >> N;
		for(int i = 0; i < N; i++) cin >> v[i];
		solve(E, 0, 0);
		cout << "Case #" << t_ << ": " << ans << endl;
	}
}

