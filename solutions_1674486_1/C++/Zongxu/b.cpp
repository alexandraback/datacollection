#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
#include <string>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iomanip>
#include <deque>
#include <list>
#include <bitset>
#include <functional>
#include <numeric>
using namespace std;

int n;
vector<int> edge[1001];
bool mk[1001];

bool go(int s) {
	for (int i=0; i<edge[s].size(); i++) {
		if (mk[ edge[s][i] ])
			return true;
		mk[ edge[s][i] ] = true;
		if (go(edge[s][i]))
			return true;
	}
	return false;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int num, tmp;
	int T; cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>n;
		for (int i=1; i<=n; i++) {
			edge[i].clear();
			cin>>num;
			for (int j=1; j<=num; j++) {
				cin>>tmp;
				edge[i].push_back(tmp);
			}
		}
		
		printf("Case #%d: ", t);
		int k;
		for (k=1; k<=n; k++) {
			memset(mk, 0, sizeof(mk));
			mk[k] = true;
			if (go(k)) {
				puts("Yes");
				break;
			}
		}
		if (k>n)
			puts("No");
	}

	return 0;
}
