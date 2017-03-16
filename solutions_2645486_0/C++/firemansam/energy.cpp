#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int tcs, n, e, r, v[10050], c[10000050], t[10000050], l[10000050], ans;
int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		ans = 0;
		scanf("%i%i%i", &e, &r, &n);
		memset(c, 0, sizeof c);
		memset(t, 0, sizeof t);
		for(int i=0;i<n;i++){
			scanf("%i", &v[i]);
			memcpy(l, t, sizeof t);
			memset(t, 0, sizeof t);
			for(int j=0;j<=e;j++){
				c[j] = v[i] * j;
				for(int k=j;k<=e;k++){
					int ne = (e - k) + r, nf = (e-k) + j;
					if(nf > e) continue;
					if(ne > e) ne = e;
					t[ne] = max(t[ne], l[nf] + c[j]);
				}
			}
		}
		for(int i=0;i<=e;i++){
			ans = max(ans, t[i]);
		}
		printf("Case #%i: %i\n", tc, ans);
	}	
}