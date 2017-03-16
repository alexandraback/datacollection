#include<cstdio>
int ten[10];
int cnt(int t){
	int r=0;
	while(t){
		t/=10;
		r++;
	}
	return r;
}
int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int ii,tt;
	int i,j,k,A,B,ans;
	ten[0]=1;
	for(i=1;i<10;i++)
		ten[i]=ten[i-1]*10;
	scanf("%d",&tt);
	for(ii=1;ii<=tt;ii++){
		printf("Case #%d: ",ii);
		scanf("%d%d",&A,&B);
		ans=0;
		for(i=A;i<=B;i++){
			j=i;
			k=cnt(i);
			while(1){
				j=j%10*ten[k-1]+j/10;
				if(j==i)break;
				if(cnt(j)==k&&j>=A&&j<=B)
					ans++;
			}
		}
		printf("%d\n",ans/2);
	}
	return 0;
}
