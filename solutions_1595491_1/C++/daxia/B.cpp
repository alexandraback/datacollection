#include<cstdio>
int a[110];
int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int ii,t;
	int i,j,k,n,s,p,ti;
	scanf("%d",&t);
	for(ii=1;ii<=t;ii++){
		printf("Case #%d: ",ii);
		scanf("%d%d%d",&n,&s,&p);
		j=0;k=0;
		for(i=0;i<n;i++){
			scanf("%d",&ti);
			if(p==0){
				if(ti>=3*p)
					j++;
			}
			else if(p==1){
				if(ti>=3*p-2)
					j++;
			}
			else{
				if(ti>=3*p-4)j++;
				if(ti==3*p-4||ti==3*p-3)k++;
			}
		}
		if(k>s)j-=k-s;
		printf("%d\n",j);
	}
	return 0;
}
