#include <string>
#include <bitset>
#include <cassert>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
using namespace std;
#include <iostream>
#include <map>
#include <cmath>

//By chyx111
#define DBG(a) do{cerr << #a << ": " << (a) << endl;}while(0)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) ((int)(a).size())
#define REP(i,n) for(int n_##__LINE__ = (n), i = 0; i < n_##__LINE__; ++i)
template<class T> ostream& operator<<(ostream& os, vector<T> v){
	REP (i, v.size()){
		if(i){
			os << ' ';
		}
		os << v[i];
	}
	return os;
};

int const N = 22;
int const MAX_SUM = 110000 * N;
bitset<MAX_SUM * 2> dp[N];
vector<int> seta, setb;
int n;
int arr[N];

bool solve(){
	memset(dp, 0, (sizeof dp));
	dp[0][MAX_SUM] = 1;
	bool found = false;
	int a, b;
	for(int i = 1; i <= n; ++i){
		REP (j, MAX_SUM * 2)if(dp[i - 1][j]){
			dp[i][j + arr[i - 1]] = true;
			dp[i][j - arr[i - 1]] = true;
			dp[i][j] = true;
			if(j - arr[i - 1] == MAX_SUM){
				a = i;
				b = j - arr[i - 1];
				found = true;
				goto end_solve;
			}
			if(j + arr[i - 1] == MAX_SUM){
				a = i;
				b = j + arr[i - 1];
				found = true;
				goto end_solve;
			}
		}
	}
end_solve:
	if(!found)return false;
	seta.clear();
	setb.clear();
	for(int i = a; i >= 1; --i){
		if(dp[i - 1][b - arr[i - 1]]){
			b -= arr[i - 1];
			seta.push_back(arr[i - 1]);
			continue;
		}
		if(dp[i - 1][b + arr[i - 1]]){
			b += arr[i - 1];
			setb.push_back(arr[i - 1]);
			continue;
		}
		assert(dp[i - 1][b]);
	}
	return true;
}


int main() {
	int ca;
	scanf("%d", &ca);
	REP (ica, ca){
		scanf("%d", &n);
		REP (i, n){
			scanf("%d", arr + i);
		}

		printf("Case #%d:\n", ica + 1);
		if(solve()){
			cout << seta << endl;
			cout << setb << endl;
			DBG(accumulate(ALL(seta), 0));
			DBG(accumulate(ALL(setb), 0));
		}else{
			puts("Impossible");
		}
	}
	return 0;
}

