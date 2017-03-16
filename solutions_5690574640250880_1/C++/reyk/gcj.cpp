#include<stdio.h>
#include<math.h>
char ans[50][50];
int min(int a,int b){return a<b?a:b;}

int main(){
	int dn;
	scanf("%d",&dn);
	for(int di=0;di<dn;di++){
		int r,c,n;
		scanf("%d %d %d",&r,&c,&n);
		printf("Case #%d:\n",di+1);
		bool swap=false;
		if(r<c){int p=r;r=c;c=p;swap=true;}
		n=r*c-n;
		int i,j;
		bool clear=true;
		for(i=0;i<r;i++)for(j=0;j<c;j++)ans[i][j]='*';
		if(n==1){
			ans[0][0]='.';
		}
		else if(c==1){
			for(i=0;i<n;i++)ans[i][0]='.';
		}
		else if(c==2){
			int t=n/2;
			for(i=0;i<t;i++){
				ans[i][0]='.';
				ans[i][1]='.';
			}
			if(n%2==1||n==2)clear=false;
		}
		else{
			if(n==4){
				ans[0][0]='.';
				ans[0][1]='.';
				ans[1][0]='.';
				ans[1][1]='.';
			}
			else if(n==6){
				ans[0][0]='.';
				ans[0][1]='.';
				ans[0][2]='.';
				ans[1][0]='.';
				ans[1][1]='.';
				ans[1][2]='.';
			}
			else if(n<=7)clear=false;
			else{
				int t=min(ceil(sqrt((double)n)),c);
				int s=n/t;
				if(n==s*t+1){
					for(i=0;i<s-1;i++){
						for(j=0;j<t;j++)ans[i][j]='.';
					}
					for(i=0;i<t-1;i++)ans[s-1][i]='.';
					ans[s][0]='.';
					ans[s][1]='.';
				}
				else{
					for(i=0;i<s;i++){
						for(j=0;j<t;j++)ans[i][j]='.';
					}
					for(i=0;i<n-s*t;i++)ans[s][i]='.';
				}
			}
		}
		ans[0][0]='c';
		if(!clear)puts("Impossible");
		else{
			if(swap){
				for(i=0;i<c;i++){
					for(j=0;j<r;j++)printf("%c",ans[j][i]);
					puts("");
				}
			}else{
				for(i=0;i<r;i++){
					for(j=0;j<c;j++)printf("%c",ans[i][j]);
					puts("");
				}
			}
		}
	}
	return 0;
}
