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

const int MAXK = 15;
int prod[MAXK];

vector <vector <int> > generate(int n, int m){
	vector <vector <int> > ans;
	if (n == 1){
		for (int j = 2; j <= m ; ++j){
			vector <int> cur;
			cur.push_back(j);
			ans.push_back(cur);
		}
		return ans;
	}
	
	vector <vector <int> > next = generate(n-1, m);
	
	
	for (int j = 2; j <= m; ++j){
		for (int i = 0; i < next.size(); ++i){
			vector <int> cur = next[i];
			cur.push_back(j);
			ans.push_back(cur);
		}
	}
	return ans;
}

int main(){
	int cases;
	cin >> cases;
	printf("Case #%d:\n", cases);
	int r, n, m, k;
	cin >> r >> n >> m >> k;
	
	vector <vector <int> > subsets = generate(n, m);
	
	// sort(subsets.begin(), subsets.end());
	
	// for (int i = 0; i < subsets.size(); ++i){
	// 	int mm = subsets[i].size();
	// 	assert(mm == n);
	// 	for (int j = 0; j < n; ++j){
	// 		printf("%d ", subsets[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// 
	
	for (int run = 1; run <= r; ++run){
		for (int i = 0; i < k; ++i){
			cin >> prod[i];
		}
		
		for (int i = 0; i < subsets.size(); ++i){
			vector <int> set = subsets[i];
			bool found;
			for (int j = 0; j < k; ++j){
				found = false;
				for (int mask = 0; mask < (1 << n); ++mask){
					int p = 1;
					//D(mask);
					for (int l = 0; l < n; ++l){
						if ((mask & (1 << l)) > 0){
							p *= set[l];
						}
					}
					if (p == prod[j]){
						found = true;
						break;
					}
				}
				if (!found) break;
			}
			if (found){
				for (int j = 0; j < n; ++j){
					printf("%d", set[j]);
				}
				printf("\n");
				break;
			}
		}
		
	}
	
    return 0;
}
