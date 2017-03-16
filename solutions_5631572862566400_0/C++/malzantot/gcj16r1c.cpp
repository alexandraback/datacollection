#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/malzantot/Documents/codingspace/gcj/C-small-attempt1.in.txt", "r", stdin);
	freopen("/Users/malzantot/Documents/codingspace/gcj/C-small-out2.txt", "w", stdout);

	#endif

	int tt;
	cin >> tt;
	for (int it=1; it <=tt; it++) {
		int n; int x;
		cin >> n;

		int graphLength = 0;
		vector<int> edge(n);
		vector<int> cntLovers(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> x;
			edge[i] = x-1;
			cntLovers[x-1]++;
		}

		for (int i = 0; i < n; i++) {
			vector<bool> visited(n, 0);
			int cur = i;
			int prev = -1;
			int prevprev = -1;
			int length = 0;
			bool loop = false;
			bool any = 0;
			while(!visited[cur]) {
				visited[cur] = true;
				prevprev = prev;
				prev = cur;
				cur = edge[cur];
				if (cur==prevprev||(cur==i)) {
					loop = true;
				}
				length++;
			}
			int add1 = 0;
			if (cntLovers[prev] > 1 && prevprev == edge[prev]) {
									add1 = 1;

						}

			int add2 = 0;
			if (prevprev == edge[prev]) {
				// find the max loop
				for (int k = 0; k < n; k++) {
					if (!visited[k]) {
						int loop_cnt = 0;

						int cur = k;
									int prev = -1;
									int prevprev = -1;
									int length = 0;
									bool loop = false;
									bool any = 0;
									while(!visited[cur]) {
										visited[cur] = true;
										prevprev = prev;
										prev = cur;
										cur = edge[cur];
										if (cur==prevprev||(cur==i)) {
											loop = true;
										}
										loop_cnt++;
									}
									if (loop){
									add2 = max(add2, loop_cnt);
									}
					}
				}
			}

			if (loop) {


			graphLength = max(graphLength, length+max(add1, add2));
			}



		}
		printf("Case #%d: %d\n", it, graphLength);

	}
	
	return 0;

}
