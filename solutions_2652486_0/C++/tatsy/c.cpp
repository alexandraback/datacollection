#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <utility>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cctype>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

#define rep(i,n) for(int i=0; i<n; i++) 
#define repa(i,s,e) for(int i=s; i<=e; i++)
#define repd(i,s,e) for(int i=s; i>=e; i--)

int T, R, N, M, K;

bool dfs(vector<int> v, int a, int d) {
	if(a == d) {
		rep(k, K) {
			if(v[k] != 1) return false;
		}
		return true;
	}

	for(int i=2; i<=M; i++) {
		vector<int> u(K);
		std::copy(v.begin(), v.end(), u.begin());
		for(int k=0; k<K; k++) {
			if(u[k] % i == 0) {
				u[k] = u[k] / i;
			}
		}

		if(dfs(u, a+1, d)) {
			printf("%d", i);
			return true;
		}
	}
	return false;
}

int main() {
	cin >> T;
	rep(t,T) {
		printf("Case #%d:\n", t+1);
		cin>>R>>N>>M>>K;

		rep(i,R) {
			vector<int> v(K);
			rep(j,K) {
				cin >> v[j];
			}
			dfs(v, 0, N);
			printf("\n");
		}
	}
}
