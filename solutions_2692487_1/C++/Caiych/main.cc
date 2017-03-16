#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int cur,n,size[1000];

int main() {
	int T;scanf("%d",&T);
	for (int cas = 1;cas <= T;cas++) {
		scanf("%d%d",&cur,&n);
		for (int i = 0;i < n;i++) 
			scanf("%d",&size[i]);
		if (cur == 1) {
			printf("Case #%d: %d\n",cas,n);
			continue;
		}
		sort(size,size+n);
		int cnt = 0;
		vector<int> tmpans;
		tmpans.clear();
		for (int i = 0;i < n;i++) {
			if (cur > size[i]) {
				cur += size[i];
			} else {
				tmpans.push_back(n - i + cnt);
				/*
				int k = ceil(log(1.0*(size[i] - 1) / (cur - 1)) / log(2.0));
				if (pow(2.0,1.0*k) == 1.0*(size[i]-1) / (cur-1))
					k++;
					*/
				while (cur <= size[i]) {
					cnt += 1;
					cur += cur - 1;
					//cur = (cur-1)*pow(2.0,1.0*k) + 1;
				}
				cur += size[i];
			}
		}
		tmpans.push_back(cnt);
		sort(tmpans.begin(),tmpans.end());
		printf("Case #%d: %d\n",cas,tmpans[0]);
	}
	return 0;
}
