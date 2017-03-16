using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl


bool has_bit(int i, int mask){
	return ((1 << i) & mask) > 0;
}
int set_bit(int i, int mask){
	return ((1 << i) | mask);
}

const int MAXK = 205;
const int MAXN = 25;
const int MAXS = 1 << 21;

vector <int> keys[MAXN];
int type[MAXN];
vector <int> i_keys;

bool seen[MAXS];
bool can[MAXS];
vector <int> memo[MAXS];

int k, n;

vector <int> solve(int mask){
	if (seen[mask]) return memo[mask];
	seen[mask] = true;
	// printf("Calling mask = %d\n", mask);
	
	vector <int> ans;
	if (mask == ((1 << n) - 1) ){
		can[mask] = true;
		return memo[mask] = ans;
	}
	
	// printf("Chests open: ");
	multiset <int> cur_keys(i_keys.begin(), i_keys.end());
	for (int i = 0; i < n; ++i){
		if (has_bit(i, mask)){
			// printf("%d ", i);
			for (int j = 0; j < keys[i].size(); j++){
				cur_keys.insert(keys[i][j]);
			}
		}
	}
	// printf("\n");
	
	for (int i = 0; i < n; ++i){
		if (has_bit(i, mask)){
			multiset <int> :: iterator it = cur_keys.find(type[i]);
			assert(it != cur_keys.end());
			cur_keys.erase(it);
		}
	}
	// printf("Has keys: ");
	// for (multiset <int> :: iterator it = cur_keys.begin(); it != cur_keys.end(); ++it){
	// 	printf("%d ", *it);
	// }
	// printf("\n");
	
	for (int i = 0; i < n; ++i){
		if (!has_bit(i, mask) and cur_keys.count(type[i]) != 0){
			int next_mask = set_bit(i, mask);
			solve(next_mask);
			if (can[next_mask]){
				ans.push_back(i);
				for (int j = 0; j < memo[next_mask].size(); ++j){
					ans.push_back(memo[next_mask][j]);
				}
				can[mask] = true;
				return memo[mask] = ans;
			}
		}
	}
	
	can[mask] = false;
	return memo[mask] = ans;
}

int main(){
	int cases; cin >> cases;
	for (int run = 1; run <= cases; ++run){
		cin >> k >> n;
		
		i_keys.resize(k);
		for (int i = 0; i < k; ++i) cin >> i_keys[i];
		
		for (int i = 0; i < n; ++i){
			int ti, ki; cin >> ti >> ki;
			type[i] = ti;
			keys[i].resize(ki);
			for (int j = 0; j < ki ; ++j) cin >> keys[i][j];
		}
		
		memset(seen, false, sizeof(seen));
		vector <int> ans = solve(0);
		
		printf("Case #%d: ", run);
		if (can[0]){
			assert(ans.size() == n);
			for (int i = 0; i < n; ++i){
				if (i != 0) printf(" ");
				printf("%d", ans[i] + 1);
			}
			printf("\n");
		}else{
			printf("IMPOSSIBLE\n");
		}
		
	}
    return 0;
}
