
#include<stdio.h>
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int in=1;in<=T;in++){
		int r,c,w;
		scanf("%d%d%d",&r,&c,&w);
		printf("Case #%d: %d\n",in,r*(c/w)+(w-1)+(c%w!=0));
	}
}
