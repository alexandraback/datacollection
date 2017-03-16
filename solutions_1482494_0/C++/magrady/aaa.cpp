#include<stdio.h>
#include<algorithm>
struct X {
	int a,b,used;
	bool operator<(X c)const {
		return b<c.b;
	}
}s[100001];
main(){
	int i,j,k;
	int T,TN,n,m,star,ans;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&s[i].a,&s[i].b);
			s[i].used=0;
		}
		m=star=ans=0;
		while(m<n){
			for(i=0;i<n;i++){
				if(s[i].used==0&&s[i].b<=star){
					star+=2-s[i].used;
					s[i].used=2;
					m++;
					ans++;
					//printf("[%d: %d]",i,2);
					break;
				}
			}
			if(i<n)continue;
			for(i=0;i<n;i++){
				if(s[i].used<2&&s[i].b<=star){
					star+=2-s[i].used;
					s[i].used=2;
					m++;
					ans++;
					//printf("[%d: %d]",i,1);
					break;
				}
			}
			if(i<n)continue;
			for(i=0;i<n;i++){
				if(!s[i].used&&s[i].a<=star){
					s[i].used=1;
					star++;
					//m++;
					ans++;
					//printf("[%d: %d]",i,1);
					break;
				}
			}
			if(i<n)continue;
			break;
		}
		if(m<n){
			printf("Case #%d: Too Bad\n",T);
		} else {
			printf("Case #%d: %d\n",T,ans);
		}
	}
}
		
