#include <cstdio>

int A,B,T;

int rot(int k, int l){
	return k / 10 + (k % 10) * l / 10;
}

int main(){
	scanf("%d", &T);
	for (int tc=1;tc<=T;++tc){
		int cnt = 0;
		scanf("%d%d", &A, &B);
		
		for (int i=A;i<=B;++i){
			int ll = 1;
			int j = i;
			
			while (j){
				j/=10;
				ll*=10;
			}
			
			for (int k=rot(i,ll);k!=i;k=rot(k,ll)){
				//printf("%d %d %d\n", i, k, cnt);
				if (A <= k && k <= B && k < i) ++cnt;
			}
			
		}
		
		printf("Case #%d: %d\n", tc, cnt);
	}
	return 0;
}