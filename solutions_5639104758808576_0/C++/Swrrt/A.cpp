#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char st[1005];
int A[1005];
int main(){
	int T,n,m,i,j,k,l,tt=0;
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		tt++;
		scanf("%d",&n);
		scanf("%s",st);
		for(i=0;i<=n;i++)A[i]=st[i]-'0';
		m=0;
		int ans=0;
		for(i=0;i<=n;i++){
			if(i<=m){
				m+=A[i];
			}else {
				ans+=i-m;
				m+=i-m;
				m+=A[i];
			}
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
