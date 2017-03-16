#include<stdio.h>
#include<string.h>

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		int x,r,c;
		scanf("%d%d%d",&x,&r,&c);
		bool f=0;
		if(x==1)f=1;
		else if(x==2){
			if(!(r%2)||!(c%2))f=1;
		}
		else if(x==3){
			if((!(r%3)&&c>=2)||(!(c%3)&&r>=2))f=1;
		}
		else if(x==4){
			if(((r%2)&&!(c%4)&&r>=3)||((c%2)&&!(r%4)&&c>=3))f=1;
			else if(!(r%2)&&!(c%2)&&(r!=2)&&(c!=2))f=1;
		}
		else if(x==5){
			if(!(r%5)){
				if(r==5&&c>=4)f=1;
				else if(r>=10&&c>=3)f=1;
			}
			else if(!(c%5)){
				if(c==5&&r>=4)f=1;
				else if(c>=10&&r>=3)f=1;
			}
		}
		else if(x==6){
			if(!((r*c)%6)&&r>=4&&c>=4)f=1;
		}
		if(f)printf("Case #%d: GABRIEL\n",q);
		else printf("Case #%d: RICHARD\n",q);
	}
	return 0;
}
