#include<cstdio>
#include<cstring>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	freopen("D.out","w",stdout);
	int T,tt=0;
	int x,r,c,flag;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&x,&r,&c);
		if(r*c%x!=0){
			flag=0;
		}
		else{
			if(x==1 || x==2){
				flag=1;
			}
			else
			if(x==3){
				if(MAX(r,c)>=3 && MIN(r,c)>=2){
					flag=1;
				}
				else{
					flag=0;
				}
			}
			else
			if(x==4){
				if(MAX(r,c)>=4 && MIN(r,c)>=3){
					flag=1;
				}
				else{
					flag=0;
				}
			}
			else
			if(x==5){
				if(MAX(r,c)>=5 && MIN(r,c)>=4){
					flag=1;
				}
				else{
					flag=0;
				}
				if(MAX(r,c)>=10 && MIN(r,c)==3){
					flag=1;
				}
			}
			else
			if(x==6){
				if(MAX(r,c)>=6 && MIN(r,c)>=4){
					flag=1;
				}
				else{
					flag=0;
				}
			}
			else{
				flag=0;
			}
		}
		printf("Case #%d: ",++tt);
		if(flag){
			puts("GABRIEL");
		}
		else{
			puts("RICHARD");
		}
	}
	return 0;
}
/*
4
2 2 2
2 1 3
4 4 1
3 2 3
 */
