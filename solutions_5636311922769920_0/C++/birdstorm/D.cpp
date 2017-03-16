#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int main() {
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	int T; cin>>T;
	for(int cs = 1, K, C, S; cs <= T; cs ++) {
		cerr << "Processing Case #" << cs <<"...\n";
		cin >> K >> C >> S;
		printf("Case #%d: ", cs);
		if(K == S) {
			for(int i = 1; i <= K; i ++) {
				printf(" %d", i);
			}
			puts("");
		}
	}
	return 0;
}

