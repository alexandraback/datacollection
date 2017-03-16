#include <stdio.h>
#include <algorithm>
using namespace std;
int D, P[1001], T, C=1;
int main(){
	scanf("%d", &T);
	while(T--){
		int ans = 10000;

		scanf("%d", &D);
		for(int i=0; i<D; ++i) scanf("%d", &P[i]);

		for(int i=1; i<=1000; ++i){
			int candi = i;
			for(int j=0; j<D; ++j)
				candi += P[j]/i + (P[j]%i>0) -1;
			ans = min(ans, candi);
		}

		printf("Case #%d: %d\n", C++, ans);
	}
}
