#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>

using namespace std;

int main(){
	int tcn, tc;
	cin >> tcn;
	for(tc = 1; tc <= tcn; ++tc){
		int n;
		cin >> n;
		vector<pair<string, string>> input(n);
		map<string, int> count[2];
		set<string> seen[2];
		set<int> todo;
		for(int i=0; i<n; ++i){
			cin >> input[i].first >> input[i].second;
			++count[0][input[i].first];
			++count[1][input[i].second];
			todo.insert(i);
		}

		int res = 0;
		int best = 0;

		for(int x = 0; x<(1<<n); ++x){
			res = 0;
			set<string> seen[2];
			for(int i=0; i<n; ++i){
				if(!((1<<i) & x)){
					seen[0].insert(input[i].first);
					seen[1].insert(input[i].second);
				}
			}
			for(int i=0; i<n; ++i){
				if((1<<i) & x){
					if(seen[0].find(input[i].first) == seen[0].end() || seen[1].find(input[i].second) == seen[1].end()){
						res = -100;
					}else{
						++res;
					}
				}
			}
			best = max(best, res);
		}
		printf("Case #%d: %d\n", tc, best);
	}
}
