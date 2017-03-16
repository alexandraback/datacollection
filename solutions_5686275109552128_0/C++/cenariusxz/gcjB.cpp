#include<stdio.h>
#include<string.h>

int a[1005];

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		int d;
		scanf("%d",&d);
		int i,m=0,j;
		for(i=1;i<=d;i++){
			scanf("%d",&a[i]);
			if(a[i]>m)m=a[i];
		}
		int ans=0x3f3f3f3f;
		for(i=1;i<=m;i++){
			int tmp=i;
			for(int j=1;j<=d;j++){
				if(a[j]>i){
					tmp+=a[j]/i-1;
					if(a[j]%i)tmp++;
				}
			}
			if(tmp<ans)ans=tmp;
		}
		printf("Case #%d: %d\n",q,ans);
	}
	return 0;
}
