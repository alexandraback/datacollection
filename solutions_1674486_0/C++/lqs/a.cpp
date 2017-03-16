#include <stdio.h>
#include <memory.h>
#include <set>

using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)

int main() {
	int T;
	scanf("%d", &T);
	FOR(ca, T) {
		printf("Case #%d: ", ca+1);
		int N;
		scanf("%d", &N);
		
		set<int> in[1000], out[1000];
		
		set<int> canfrom[1000];
		
		FOR(i, N) {
			in[i].clear();
			out[i].clear();
			canfrom[i].clear();
		}
		
		FOR(i, N) {
			int t;
			scanf("%d", &t);
			FOR(j, t) {
				int x;
				scanf("%d", &x);
				x--;
			//	printf("%d --> %d\n", i, x);
				out[i].insert(x);
				in[x].insert(i);
			}
		}
		
		bool modf = 1;
		while (modf) {
			modf = 0;
			FOR(i, N) {
				//printf("%d: %d %d\n", i, in[i].size(), out[i].size());
				if (in[i].size() == 0 && out[i].size() > 0) {
				//	printf("check %d\n", i);
					
					for (set<int>::iterator it = out[i].begin(); it != out[i].end(); it++) {
						int from = i, to = *it;
						in[to].erase(from);
//						printf("::: %d --> %d\n", from, to);
						canfrom[to].insert(from);
						for (set<int>::iterator it2 = canfrom[from].begin(); it2 != canfrom[from].end(); it2++) {
							if (canfrom[to].find(*it2) != canfrom[to].end()) {
								printf("Yes\n");
								goto done;
							}
						//	printf("=== %d --> %d\n", *it2, to);
							canfrom[to].insert(*it2);
						}
					}
					modf = 1;
					out[i].clear();
				}
				
			}
		}
		printf("No\n");
			
done:;
			
		
	}
	
	
}
