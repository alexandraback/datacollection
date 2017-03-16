#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 267
using namespace std;
char ch[267][267];
int T;
int main(){
    //freopen("C-small-attempt10.in","r",stdin);
    //freopen("C-small-attempt10.out","w",stdout);
	scanf("%d",&T);
	int n,m,k,num=1; 
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		printf("Case #%d:\n",num);
 		num++;
		if (k>=n*m){
			printf("Impossible\n");
		}
		if (n==1||m==1){
			if (n==1){
				printf("c");
				for(int i=2;i<=m-k;i++) printf(".");
				for(int i=m-k+1;i<=m;i++) printf("*");
				printf("\n");
			}
			else if (m==1){
				printf("c\n");
				for(int i=2;i<=n-k;i++) printf(".\n");
				for(int i=n-k+1;i<=n;i++) printf("*\n");
			}
		}
		else if (n==2||m==2){
			if (n==2){
				if ((k%2==0)&&(k<=n*m-4)){
				    printf("c");
				    for(int i=2;i<=m-(k/2);i++) printf(".");
				    for(int i=m-(k/2)+1;i<=m;i++) printf("*");
	    			printf("\n");
				    for(int i=1;i<=m-(k/2);i++) printf(".");
				    for(int i=m-(k/2)+1;i<=m;i++) printf("*");
				    printf("\n");
				}else{
					if (k==n*m-1){
						printf("c");
						for(int i=2;i<=m;i++) printf("*");
						printf("\n");
						for(int i=1;i<=m;i++) printf("*");
						printf("\n");
					}
					else printf("Impossible\n");
				}
			}
			else if (m==2){
				if ((k%2==0)&&(k<=n*m-4)){
					printf("c.\n");
				    for(int i=2;i<=n-(k/2);i++) printf("..\n");
				    for(int i=n-(k/2)+1;i<=n;i++) printf("**\n");
 				}else{
					if (k==n*m-1){
						printf("c*\n");
						for(int i=2;i<=n;i++) printf("**\n");
					}
					else printf("Impossible\n");
				}
			}
		}
		else{ 
			if ((k==n*m-7)||(k==(n*m-5))||(k==(n*m-3))||(k==(n*m-2))){
				printf("Impossible\n");
				continue;
			}
			for(int i=1;i<=n;i++)
			    for(int j=1;j<=m;j++) ch[i][j]='*';
			if(k==(n*m-1)){
				ch[1][1]='c'; 
				for(int i=1;i<=n;i++){
				        for(int j=1;j<=m;j++) printf("%c",ch[i][j]);
				        printf("\n");
			    }
			    continue;
			}
			if (k==n*m-8){
				ch[1][1]=ch[1][2]=ch[1][3]=ch[2][1]=ch[2][2]=ch[2][3]=ch[3][1]=ch[3][2]='.';
				ch[1][1]='c';
			}
			else if (k==n*m-6){
				ch[1][1]=ch[1][2]=ch[1][3]=ch[2][1]=ch[2][2]=ch[2][3]='.';
				ch[1][1]='c';
			}
			else if (k==n*m-4){
				ch[1][2]=ch[2][1]=ch[2][2]='.';
				ch[1][1]='c';
			}
			else if (k<=(n-2)*(m-2)){
				for(int i=1;i<=n;i++)
			        for(int j=1;j<=m;j++) ch[i][j]='.';
				int tot=0;
				for(int i=1;i<=n-2;i++)
				    for(int j=1;j<=m-2;j++){
						tot++;
						if (tot>k) break;
						ch[n-i+1][m-j+1]='*';
					}
				ch[1][1]='c';
			}
			else{
				int tot=0;
				if ((n*m-k)%2==1){
					ch[3][3]='.';
					k++;
				}
				k=n*m-k;
				k--;k--;ch[3][1]=ch[3][2]='.';
				for(int i=1;i<=m;i++){
					tot++;tot++;
					if(tot>k) break;
					ch[1][i]=ch[2][i]='.';  
				}
				if(tot<k){
					for(int i=4;i<=n;i++){
						tot++;tot++;
						if (tot>k) break;
						ch[i][1]=ch[i][2]='.';
					}
				}
				ch[1][1]='c';
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++) printf("%c",ch[i][j]);
				printf("\n");
			}
		}
	} 
	return 0;
}  
