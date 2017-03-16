#include <stdio.h>
int main(){
	int test,temp,t;
	scanf("%d",&test);
	for (t = 1; t <= test; ++t)
	{
		printf("Case #%d: ",t);
		int n,m,k,ans;
		scanf("%d%d%d",&n,&m,&k);
		if(n>m){
			temp=n;
			n=m;
			m=temp;
		}
		if(n<3){
			ans=k;
		}
		else if(n==3){
			if(m==3){
				if(k<=4){
					ans=k;
				}
				else if(k==5){
					ans=4;
				}
				else{
					ans=(k-5)+4;
				}
			}
			else if(m==4){
				if(k<=4)
					ans=k;
				else if(k==5)
					ans=4;
				else if(k==6)
					ans=5;
				else if(k==7||k==8)
					ans=6;
				else
					ans=(k-6)+4;
			}
			else if(m==5){
				if(k<=4)
					ans=k;
				else if(k==5)
					ans=4;
				else if(k==6)
					ans=5;
				else if(k==7||k==8)
					ans=6;
				else if(k==9)
					ans=7;
				else if(k==10||k==11)
					ans=8;
				else if(k==12)
					ans=9;
				else if(k==13)
					ans=10;
				else if(k==14)
					ans=11;
				else if(k==15)
					ans=12;
			}
			else if(m==6){
				if(k<=4)
					ans=k;
				else if(k==5)
					ans=4;
				else if(k==6)
					ans=5;
				else if(k==7||k==8)
					ans=6;
				else if(k==9)
					ans=7;
				else if(k==10||k==11)
					ans=8;
				else if(k==12)
					ans=9;
				else if(k==13||k==14)
					ans=10;
				else if(k==15)
					ans=11;
				else if(k==16)
					ans=12;
				else if(k==17)
					ans=13;
				else if(k==18)
					ans=14;
			}
		}
		else if(n==4){
			if(m==4){
				if(k<=4)
				ans=k;
				else if(k==5)
					ans=4;
				else if(k==6)
					ans=5;
				else if(k==7||k==8)
					ans=6;
				else if(k==9)
					ans=7;
				else if(k==10||k==11||k==12)
					ans=8;
				else if(k==13)
					ans=9;
				else if(k==14)
					ans=10;
				else if(k==15)
					ans=11;
				else if(k==16)
					ans=12;
			}
			if(m==5){
				if(k<=4)
				ans=k;
				else if(k==5)
					ans=4;
				else if(k==6)
					ans=5;
				else if(k==7||k==8)
					ans=6;
				else if(k==9)
					ans=7;
				else if(k==10||k==11||k==12)
					ans=8;
				else if(k==13)
					ans=9;
				else if(k==14||k==15||k==16)
					ans=10;
				else if(k==17)
					ans=11;
				else if(k==18)
					ans=12;
				else if(k==19)
					ans=13;
				else if(k==20)
					ans=14;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}