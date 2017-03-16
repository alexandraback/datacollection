#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

#define INF 1000000000

const double PI = acos(-1.0);

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pii > vpii;
typedef long long ll;

int T, N, M, K, R;
int S[7];
int B[3];
set<int> all_subsets;

inline void make_subsets() {
	all_subsets.clear();
	for(int bit = 0; bit < (1 << N); bit++) {
		int pro = 1;
		for(int p=0; p<N; p++) {
			if (bit & (1 << p)) {
				pro *= B[p];
			}
		}
		all_subsets.insert(pro);
	}
	return;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	printf("Case #1:\n");
	scanf("%d%d%d%d", &R, &N, &M, &K);
	for (int line=0; line<R; line++) {
		bool is_bad = 0;
		bool finished = 0;
		for(int i=0; i<K; i++) {
			scanf("%d", &S[i]);
		}
		for(int a=2; a<=M; a++) {

			if(finished) break;
			for(int b=a; b<=M; b++) {
				if(finished) break;
				for(int c=b; c<=M; c++) {
					if(finished) break;
					is_bad = 0;
					B[0] = a; B[1] = b; B[2] = c;
					make_subsets();
					for(int i=0; i<K; i++) {
						if (all_subsets.find(S[i]) == all_subsets.end()) {
							is_bad = 1;
							break;
						}
					}
					if (is_bad) continue;
					for(int i=0; i<N; i++) {
						putchar(char(B[i]) + '0');
					}
					putchar('\n');
					finished = 1;
				}
			}
		}
		if (!finished) {
			for(int i=0; i<N; i++) {
				putchar('0');
			}
			putchar('\n');
		}
	}


	return 0;
}