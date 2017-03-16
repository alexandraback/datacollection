#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int d[100];
int e[100];
int main(){
	int a;
	scanf("%d",&a);
	int T=0;
	while(a--){
		T++;
		int b,c;scanf("%d%d",&b,&c);
		for(int i=0;i<c;i++){
			scanf("%d",d+i);
		}
		std::sort(d,d+c);
		if(b==1){
			printf("Case #%d: %d\n",T,c);
			continue;
		}
		int now=b;
		for(int i=0;i<c;i++)e[i]=99999999;
		int v=0;
		for(int i=0;i<c;i++){
			if(now>d[i]){
				e[i]=v;
				now+=d[i];
			}else{
				//int r=now-1;
				for(int j=1;;j++){
					now+=now-1;v++;
					if(now>d[i]){
						e[i]=v;
						//now+=r;
						now+=d[i];
						break;
					}
				}
			}//printf("%d ",e[i]);
		}
		int ret=c;
		for(int i=0;i<c;i++){
			ret=min(ret,e[i]+(c-i-1));
		}
		printf("Case #%d: %d\n",T,ret);
	}
}