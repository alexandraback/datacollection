#include <vector> 
#include <string> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <stack> 
#include <queue> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <cctype> 
#include <cassert> 
#include <memory.h> 

using namespace std;
vector<int> edge[1001];
bool ck[1001];
bool flag;
void dfs(int idx) {
	ck[idx] = true;
	for(int i=0;i<edge[idx].size();i++) {
		if(ck[edge[idx][i]] == 1) {
			flag = true;
		} else {
			dfs(edge[idx][i]);
		}
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for(int q=1;q<=T;q++) {
		int N;
		scanf("%d", &N);
		for(int i=1;i<=N;i++) {
			edge[i].clear();
			int m;
			scanf("%d", &m);
			for(int j=0;j<m;j++) {
				int t;
				scanf("%d", &t);
				edge[i].push_back(t);
			}
		}
		flag = false;
		for(int i=0;i<N;i++) {
			memset(ck, 0, sizeof(ck));
			dfs(i+1);
			if(flag) break;
		}
		printf("Case #%d: ", q);	
		if(flag) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}

	}
	return 0;
}
