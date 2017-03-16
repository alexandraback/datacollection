#include<stdio.h>
#include<algorithm>
#include<string>
int a[1001];
int s[1001];
int main(){
	int T,TN;
	int i,j,k;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		int n;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			a[i]--;
		}
		for(k=n;k>=2;k--){
			for(i=0;i<k;i++){
				s[i]=i;
			}
			do {
				for(i=0;i<k;i++){
					int prev=(i-1+k)%k;
					int next=(i+1+k)%k;
					if(s[prev]!=a[s[i]]&&s[next]!=a[s[i]]){
						break;
					}
				}
				if(i>=k) break;
			} while(std::next_permutation(s,s+n));
			if(i>=k) break;
		}
		printf("Case #%d: %d\n",T,k);
	}
}
