#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, inp[512];
vector<int> comp[2000005];
int sum = 0;

int test(int bm) {
	for (int i=0;i< 1<<20;++i) {
		if (i & bm) continue;
		int s = 0;
		for (int j=0;j<N;++j) {
			if ( (i & (1 << j)) > 0) {
				s += inp[j];
			}
		}
		if (s == sum) return i;
	}
	return 0;
	
}

void pr(int a) {
	for (int j=0;j<N;++j) {
		if ( (a & (1 << j)) > 0) {
			printf("%d ", inp[j]);
		}
	}
	printf("\n");
}
void output(int a, int b) {
	pr(a); pr(b);
}
int main() {
	int T;
	scanf(" %d", &T);
	for (int i=1;i<=T;++i) {
		printf("Case #%d:\n", i);
		
		for (int i=0;i<2000001;++i) comp[i].clear();
		
		scanf(" %d", &N);
		for (int i=0;i<N;++i ){
			scanf(" %d", &inp[i]);
		}
		sort(inp, inp+N);
		
		int tmp = inp[0];
		for (int i=1;i<N;++i) {
			if (tmp >= inp[1]) {
				
			}
		}
		
		bool found = false;
		for (int i=1;i<1<<20;++i) {
			sum = 0;
			for (int j=0;j<N;++j) {
				if ( (i & (1 << j)) > 0) {
					sum += inp[j];
				}
			}
			for (int j =0;j<comp[sum].size();++j) {
				if ((i & (comp[sum][j])) == 0) {
//				printf("found %d %d\n", i, *vi);
					output(i, comp[sum][j]);
					found = true;
					break;
				}
			}
			if (found) break;
//			printf("ins %d %d\n", sum, i);
			comp[sum].push_back(i);
			
			/*int x = test(i);
			if (x) {
				for (int j=0;j<N;++j) {
					if ( (i & (1 << j)) > 0) {
						printf("%d ", inp[j]);
					}
				}
				printf("\n");
				for (int j=0;j<N;++j) {
					if ( (x & (1 << j)) > 0) {
						printf("%d ", inp[j]);
					}
				}
				printf("\n");
				found = true;
				break;
			}*/
		}
		if (found == false) {
			printf("Impossible\n");
		}
	}
	return 0;
}
