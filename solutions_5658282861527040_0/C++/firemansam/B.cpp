#include <bits/stdc++.h>
using namespace std;
int tcs, a, b, k;
int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		scanf("%i%i%i", &a, &b, &k);
		int ans = 0;
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				if((i & j) < k) ans++;
			}
		}
		printf("Case #%i: %i\n", tc, ans);
	}
}