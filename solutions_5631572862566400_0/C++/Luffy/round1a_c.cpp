#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <string.h>

using namespace std;

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};

int main(){
	freopen("output.txt","w",stdout);
	freopen("input.in","r",stdin);
	int T;
	cin >> T;
	int n;
	//int a, b; // tmp use
	int cur_len, cur, next, ans;
	map<pair<int, int>, int>::iterator iter;
	int input[1001];
	int visited[1001];
	for (int t=1; t<=T; t++) {
		cin >> n;
		for (int i=1; i<=n; i++) 
			scanf("%d", &input[i]);
		ans = 0;
		map<pair<int, int>, int> nice_ends;
		for (int start = 1; start <= n; start++) {
			// start with start
			//printf("yo start at %d\n", start);
			memset(visited, 0, sizeof(visited));
			//for (int i=1; i<=n; i++) {
			//	printf(" %d", visited[i]);
			//}
			cur_len = 1;
			visited[start] = 1;
			cur = start;
			while (true) {
				next = input[cur];
				//printf("yo %d\n", next);
				if (visited[next] == 0) {
					//printf("new bro\n");
					visited[next] = 1;
					cur_len++;
					cur = next;
				}
				else {
					//printf("gg time\n");
					// loop
					if (input[next] == cur) {
						// nice end
						pair<int, int> p = make_pair(cur, next);
						if (nice_ends.find(p)!= nice_ends.end()) {
							if (nice_ends[p] < cur_len)
								nice_ends[p] = cur_len;
						}else {
							nice_ends[p] = cur_len;
						}
						//printf("%d got nice end %d\n", start, cur_len);
						break;
					}
                    else if (next == start) {
						// perfect loop
						//printf("loop at %d\n", start);
						if (cur_len> ans) ans = cur_len;
						break;
					}
					else {
						// start gg
						//printf("%d gg\n", start);
						break;
					}
				}
			}
		}
		//printf("cur ans: %d\n", ans);
		if (nice_ends.size() == 0) {
			// ans = ans
			//printf("1");
		}else if (nice_ends.size() == 1) {
			ans = max(ans, int(nice_ends.begin()->second));
			//printf("2: %d\n", nice_ends.begin()->second);
		}else {
			//sort(nice_ends.begin(), nice_ends.end(), less_second<pair<int, int>, int>());
			vector<pair<pair<int, int> , int> > vecmap;
			for (iter = nice_ends.begin(); iter!=nice_ends.end(); iter++) {
				vecmap.push_back(make_pair(iter->first, iter->second));
			}
			sort(vecmap.begin(), vecmap.end(), less_second<pair<int, int>, int>());
			//cerr << vecmap[0].second << "\n";
			//cerr << vecmap[1].second << "\n";
			if (vecmap[0].first.first == vecmap[1].first.second &&
				vecmap[0].first.second == vecmap[1].first.first) {
				ans = max(ans, vecmap[0].second + vecmap[1].second - 2);
				if (vecmap.size() >= 3) 
					ans = max(ans, vecmap[0].second + vecmap[2].second);
			}else {
				ans = max(ans, vecmap[0].second + vecmap[1].second);
			}
			// int max1=0, max2=0, max3=0;
			// printf("3");
			// for (iter = nice_ends.begin(); iter!=nice_ends.end(); iter++) {
			// 	if (iter->second >= max1) {
			// 		max1 = iter->second;
			// 		max2 = max1;
			// 	}else if (iter->second >= max2) {
			// 		max2 = iter->second;
			// 		max3 = max2;
			// 	}else if (iter->second >= max3) {
			// 		max3 = iter->second;
			// 	}
			// }
			// ans = max(ans, max1+max2);
			// sort()
		}
		printf("Case #%d: %d\n", t, ans);
	}
}