#include <stdio.h>
#include <algorithm>
using namespace std;

int v[100];

int main(){
	int T;
	scanf("%d", &T);
	for(int TT=1;TT<=T;TT++){
		int _a, n;
		scanf("%d%d", &_a, &n);
		long long a = _a;
		for(int i=0;i<n;i++){
			scanf("%d", &v[i]);
		}
		sort(v, v+n);

		int v1 = 0;
		int ret = n;
		if(a == 1){
			ret = n;
		}else{
			for(int i = 0; i < n;i++){
				while(a <= v[i]){
					v1++;
					a += a-1;
				}
				ret = min(v1+n-i-1, ret);
				a += v[i];
			}
		}

		printf("Case #%d: %lld\n", TT, ret);
	}
}

