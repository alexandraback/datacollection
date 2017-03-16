#include <bits/stdc++.h>

using namespace std;

long long t,tes,k,c,s,i,x;
vector<long long> ans;

long long pou(long long x, long long y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	if (y % 2 == 1) return x * pou(x,y-1);
	long long z = pou(x,y/2);
	return z * z;
}

void DFS(long long depth, long long sum) {
	if (depth == c || x == k) {
		ans.push_back(sum);
	} else {
		x++;
		DFS(depth+1,sum+(x-1)*pou(k,c-(depth+1)));
	}
}

int main() {
	scanf("%lld",&t);
	for (tes=1 ; tes<=t ; tes++) {
		scanf("%lld%lld%lld",&k,&c,&s);
		x = 0;
		ans.clear();
		while (x < k) {
			x++;
			DFS(1,(x-1)*pou(k,c-1));
		}
		printf("Case #%lld:",tes);
		if (ans.size() <= s) {
			for (i=0 ; i<ans.size() ; i++) {
				printf(" %lld",1+ans[i]);
			}
			printf("\n");
		} else {
			printf("IMPOSSIBLE\n");
		}
	}
}