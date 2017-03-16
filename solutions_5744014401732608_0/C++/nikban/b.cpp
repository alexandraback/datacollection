#include<bits/stdc++.h>
using namespace std;

long long int mylog(long long int x){
	long long int ans=0;
	while(x!=1){
		x=x/2;
		ans++;
	}
	return ans;
}

long long int mypow(long long int x, long long int y){
	if(y==0)
		return 1;
	long long int z=mypow(x, y/2);
	if(y%2==0)
		return z*z;
	else
		return z*z*x;
}

int main(){
	long long int t, b, m, k, ans[55][55], rem, i, j, powerk;
	scanf("%lld",&t);

	for(int cas=1;cas<=t;cas++){
		printf("Case #%d: ",cas);

		scanf("%lld%lld", &b, &m);

		for(i=0;i<b;i++){
			ans[i][i+1]=1;
		}

		k=mylog(m);
		powerk=mypow(2,k);
		rem=m-powerk;
		if((rem==0 && b<k+2) || (rem>0 && b<k+3)){
			printf("IMPOSSIBLE\n");
			continue;
		}

		for(i=0;i<k;i++){
			for(j=i+1;j<k+2;j++){
				ans[i][j]=1;
			}
		}

		i=0;
		while(rem!=0){
			if(rem%2==1){
				ans[k-i][k+2]=1;
			}
			rem/=2;
			i++;
		}

		printf("POSSIBLE\n");
		for(i=0;i<b;i++){
			for(j=0;j<b;j++){
				printf("%lld", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}