#include<cstdio>
int t,r,c,w,d;
int main(){
	freopen("t.in","r",stdin);
	freopen("t.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		++d;
		printf("Case #%d: ",d);
		scanf("%d%d%d",&r,&c,&w);
		if(c%w==0)
			printf("%d\n",r*(c/w)+w-1);
		else
			printf("%d\n",r*(c/w)+w);
		}
	}
