#include <bits/stdc++.h>

using namespace std;

int d[1009];

int main(){
	freopen("D-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;scanf("%d",&tc);
	for(int tcno=1;tcno<=tc;tcno++){
		int x,r,c;scanf("%d%d%d",&x,&r,&c);
		if(x==1){
			printf("Case #%d: GABRIEL\n",tcno);
		}
		else if(x==2){
			if((r*c)%2==0){
				printf("Case #%d: GABRIEL\n",tcno);
			}
			else{
				printf("Case #%d: RICHARD\n",tcno);
			}
		}
		else if(x==3){
			if((r*c)%3){
				printf("Case #%d: RICHARD\n",tcno);
			}
			else{
				if(r<=1||c<=1){
					printf("Case #%d: RICHARD\n",tcno);
				}
				else{
					printf("Case #%d: GABRIEL\n",tcno);
				}
			}
		}
		else if(x==4){
			if((r*c)%4){
				printf("Case #%d: RICHARD\n",tcno);
			}
			else{
				if(r<=1||c<=1||max(r,c)<4||min(r,c)<3){
					printf("Case #%d: RICHARD\n",tcno);
				}
				else{
					printf("Case #%d: GABRIEL\n",tcno);
				}
			}
		}
	}
}
