#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

using std::map;
using std::sort;
using std::vector;

map<int,int> count;
int T, N, in;
vector<int> lst;


int main() {
	scanf("%d", &T);
	for(int tc=1; tc<=T; ++tc) {
		count = map<int,int>();
		lst = vector<int>();
		scanf("%d", &N);
		for(int i=0; i<N+N-1; ++i) {
			for(int j=0; j<N; ++j) {
				scanf("%d", &in);
				count[in] = count[in] + 1;
			}
		}
		for(auto it=count.begin(); it!=count.end(); ++it) {
			if(it->second % 2) {
				lst.push_back(it->first);
			}
		}
		sort(lst.begin(), lst.end());
		printf("Case #%d:", tc);
		for(auto it=lst.begin(); it!=lst.end(); ++it) {
			printf(" %d", *it);
		}
		printf("\n");
	}
	return 0;
}