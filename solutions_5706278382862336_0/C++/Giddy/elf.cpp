#include<stdlib.h>
#include<stdio.h>
using namespace std;

int factor(int p,int q){
	if(p==0)return q;
	if(q==0)return p;
	if(p==1||q==1)return 1;
	if(p>=q)return factor(p%q,q);
	if(q>p)return factor(p,q%p);
}

int main(){
	int time;
	scanf("%d",&time);
	for(int t=1;t<=time;t++){
		int P,Q;
		scanf("%d/%d",&P,&Q);
		int f = factor(P,Q);
		P = P/f; Q = Q/f;
		bool flag = true;
		int qq = Q;
		while(qq){
			if(qq%2&&qq>1){
				flag = false; break;
			}
			qq/=2;
		}
		printf("Case #%d: ",t);
		if(!flag)
			printf("impossible\n");
		else{
			int x=1;
			while(1){
				if(P>=(Q/2))break;
				x++;
				Q/=2;
			}
			printf("%d\n",x);
		}
	}
}
