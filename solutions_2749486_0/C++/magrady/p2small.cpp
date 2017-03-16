#include<stdio.h>
#include<string.h>
char s[1000001];
char rec[100001];
bool ok;
void go(int dis,int lim,int x,int y){
	//printf("%d %d %d %d\n",dis,lim,x,y);
	if(!x&&!y){
		ok=1;
		printf("ok %s\n",rec);
	}
	/*if(ok){
		return;
	}*/
	if(dis>lim){
		return;
	}
	rec[dis-1]='E',go(dis+1,lim,x-dis,y);//if(ok)return; //E
	rec[dis-1]='W',go(dis+1,lim,x+dis,y);//if(ok)return; //W
	rec[dis-1]='N',go(dis+1,lim,x,y-dis);//if(ok)return; //N
	rec[dis-1]='S',go(dis+1,lim,x,y+dis);//if(ok)return; //S
}
int main(){
	int i,j,k;
	int T,TN,x,y;
	long long ans;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",T);
		if(x>0){
			for(i=0;i<x;i++){
				printf("WE");
			}
		}
		if(x<0){
			for(i=0;i<-x;i++){
				printf("EW");
			}
		}
		if(y>0){
			for(i=0;i<y;i++){
				printf("SN");
			}
		}
		if(y<0){
			for(i=0;i<-y;i++){
				printf("NS");
			}
		}
		puts("");
	}
}
