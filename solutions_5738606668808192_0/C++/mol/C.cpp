#include <stdio.h>

long long int pow(int a, int b){
	long long int ans = 1;
	for(int i=0; i<b; i++)
		ans *= a;
	return ans;
}

long long int divisor(long long int n){
	long long int ret = 0;
	for(long long int i=2; i*i<=n; i++)
		if(n%i == 0){
			ret = i;
			break;
		}
	return ret;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		int N,J;
		scanf("%d%d",&N,&J);
		printf("Case #%d:\n",i+1);
		int cnt = 0;
		for(int j=0; j<2<<(N-2); j++){
			char bits[N];	// from left to right
			bits[0] = 1;
			bits[N-1] = 1;
			for(int k=1; k<N-1; k++)
				bits[k] = (j>>(N-2-k))%2;
			long long int divis[11];
			int flg = 1;
			for(int k=2; k<=10; k++){
				long long int tmp = 0;
				for(int kk=0; kk<N; kk++)
					tmp += bits[kk]*pow(k,N-1-kk);
//				printf("%lld\n",tmp);
				divis[k] = divisor(tmp);
				if(divis[k] == 0){
					flg = 0;
					break;
				}
			}
			if(flg){
				cnt++;
				for(int k=0; k<N; k++)
					printf("%d",bits[k]);
				for(int k=2; k<=10; k++)
					printf(" %lld",divis[k]);
				printf("\n");
			}
			if(cnt >= J)
				break;
		}
	}
	return 0;
}
