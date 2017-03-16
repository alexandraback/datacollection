#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n,i,j,k,a[5][5],end=1,ans=-1;
	char c;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		ans=-1;
		end=1;
		scanf("\n");
		for(j=1;j<=4;j++){
			scanf("\n");
			for(k=1;k<=4;k++){
				scanf("%c",&c);
				if(c=='X')a[j][k]=1;
				if(c=='O')a[j][k]=10;
				if(c=='T')a[j][k]=100;
				if(c=='.')a[j][k]=0,end=0;
			}
		}
		for(j=1;j<=4;j++){
			int sum=0;
			for(k=1;k<=4;k++){
				sum+=a[j][k];
			}
			if(sum==4||sum==103)ans=1;
			if(sum==40||sum==130)ans=0;
		}
		
			for(j=1;j<=4;j++){
			int sum=0;
			for(k=1;k<=4;k++){
				sum+=a[k][j];
			}
			if(sum==4||sum==103)ans=1;
			if(sum==40||sum==130)ans=0;
		}
		
		    int sum;
		    sum=a[1][1]+a[2][2]+a[3][3]+a[4][4];
		    if(sum==4||sum==103)ans=1;
			if(sum==40||sum==130)ans=0;
			
		    sum=a[1][4]+a[2][3]+a[3][2]+a[4][1];
		    if(sum==4||sum==103)ans=1;
			if(sum==40||sum==130)ans=0;
			
			
			printf("Case #%d: ",i);
			if(ans==-1){
				if(end==1)printf("Draw\n");
				if(end==0)printf("Game has not completed\n");
			}
			if(ans==0)printf("O won\n");
			if(ans==1)printf("X won\n");
		
		
		
	}

	return 0;
}
