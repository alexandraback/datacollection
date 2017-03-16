#include <cstdio>
#include <map>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); \
                        it != (v).end(); ++it)


int main() {
	int T;
	scanf("%d",&T);
	int S[20];
	rep(t,0,T) {
		printf("Case #%d:\n", t+1);
		int N;
		scanf("%d",&N);
		rep(n,0,N) {
			scanf("%d",S+n);
		}
		map<int,int> sol;
		bool imp = true;
		rep(sub, 1, 1<<N) {
			int sum = 0;
			rep(i,0,N) {
				if(sub & (1<<i))
					sum+=S[i];
			}
			if (sol.count(sum)) {
				// Print
				bool first = true;
				rep(i,0,N) {
					if(sub & (1<<i)) {
						if (!first) {
							printf(" ");
						} else {
							first = false;
						}
						printf("%d",S[i]);
					}
				}
				printf("\n");
				first = true;
				rep(i,0,N) {
					if(sol[sum] & (1<<i)) {
						if (!first) {
							printf(" ");
						} else {
							first = false;
						}
						printf("%d",S[i]);
					}
				}
				printf("\n");
				
				
				imp = false;
				break;
			}
			sol[sum] = sub;
		}
		if (imp) {
			printf("Impossible\n");
		}
	}
	return 0;
}