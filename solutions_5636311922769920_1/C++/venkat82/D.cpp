#include <bits/stdc++.h>
using namespace std;
int main(){
	int test;
	scanf("%d", &test);
	for (int w = 1; w <= test; w++) {
		int k, c, s;
		cin>>k>>c>>s;
		printf("Case #%d:", w);
		int need = (k + c - 1) / c;
		if(need > s) {
			printf(" IMPOSSIBLE\n");
			continue;
		} 
		for (int i = 0; i < need; i++) {
			long long common = i * c;
			int st = i * c, en = min((i + 1) * c, k);
			for (int j = st + 1; j < en; j++) common = common * k + j; 
			for (int j = en; j < (i + 1) * c; j++) common *= k; 
			printf(" %lld", common + 1);
		}
		printf("\n");
	}
}