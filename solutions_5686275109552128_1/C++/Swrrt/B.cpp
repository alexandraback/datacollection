#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int A[1005];
int main(){
	int T,n,m,i,j,k,l,tt=0;
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for(tt=1;tt<=T;tt++){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&A[i]);
		}
		int ans=1000000;
		for(j=1;j<=1000;j++){
			int s=0;
			for(i=1;i<=n;i++){
				if(A[i]>j){
					s+=(A[i]-1)/j;
				}
			}
			ans=min(j+s,ans);
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
