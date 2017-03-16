#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

map<int,int> cnt;

int main() {
	int T, C, n, d;
	scanf("%d", &T);
	for (C=1;C<=T;++C) {
		scanf("%d",&n);
		cnt.clear();
		int num = n + n - 1;
		for (int i=0; i<num; ++i) {
			for (int j=0; j<n; ++j)
				scanf("%d", &d), ++cnt[d];
		}
		printf("Case #%d:", C);
		for (auto it=cnt.begin();it!=cnt.end();++it) {
			it->second &= 1;
			if (it->second)
				printf(" %d", it->first);
		}
		puts("");
	}
	return 0;
}

