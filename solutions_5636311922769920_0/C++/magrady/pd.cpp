#include<stdio.h>
#include<algorithm>
int dig[1001];
long long ans[1001];
long long w(int* d,int n,int b){
	long long r=0;
	for(int i=0;i<n;i++){
		r=r*b+d[i];
	}
	return r;
}
int main(){
	int i,j,k;
	int TN;
	scanf("%d",&TN);
	for(int T=1;T<=TN;T++){
		int n,m,s;
		scanf("%d%d%d",&n,&m,&s);
		if(s*m<n){
			printf("Case #%d: IMPOSSIBLE\n",T);
		} else {
			k=0;
			for(i=0;i<s;i++){
				for(j=0;j<m;j++){
					dig[j]=k++%n;
				}
				ans[i]=w(dig,m,n);
			}
			std::sort(ans,ans+s);
			s=std::unique(ans,ans+s)-ans;
			printf("Case #%d:",T);
			for(i=0;i<s;i++){
				printf(" %lld",ans[i]+1);
			}
			puts("");
		}
	}
}
			
