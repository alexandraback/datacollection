#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int t[1003];
int D;
int main(){
	int TC;
	int val;
	scanf("%d",&TC);
	for(int tt=1;tt<=TC;++tt){
		printf("Case #%d: ", tt);
		int ans = 12345678;
		scanf("%d",&D);
		for(int i=0;i<D;++i){
			scanf("%d",&t[i]);
		}
		for(int k = 1000; k >= 1; --k){
			int sum = 0;
			for(int i=0;i<D;++i){
				if(t[i] <= k) continue;
				int c = t[i]/k;
				if (t[i]%k != 0) ++c;
				sum += (c-1);
			}
			ans = min(ans, k+sum);
		}
		printf("%d\n",ans);
	}
}