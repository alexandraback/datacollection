#include<stdio.h>
//FAKE SOULTION
//WITH edit by hand = =
int a[101],b[111];
int dp[2000001],pd[2000001],c,u[1111],u2[1111];
int dp2[2000001],pd2[2000001],c2;
main(){
	int T,TN;
	int i,j,k,p;
	int n,m;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d",&n);
		c=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			c+=a[i];
		}
		printf("Case #%d:",T);
		for(i=0;i<=c;i++)dp[i]=0;
		dp[0]=1;
		for(p=0;p<n;p++){
			for(j=c;j>=a[p];j--){
				if(dp[j-a[p]]&&!dp[j]){
					dp[j]=1;
					pd[j]=p;
				}
			}
			u[p]=0;
		}
		/*for(j=0;j<=c;j++){
			printf("%d: %d\n",j,dp[j]);
		}*/
		//if(!dp[c])continue;
		for(i=c-(c%1);i>2;i-=2){
			if(dp[i]&&dp[i>>1]){
				for(j=i>>1;j>0;j-=a[pd[j]]){
					//printf("%d(%d) ",a[pd[j]],j);
					u[pd[j]]=1;
				}
				//puts("");
				k=0;
				c2=0;
				for(p=0;p<n;p++){
					if(!u[p]){
						b[k++]=a[p];
						c2+=a[p];
					}
				}
				c2=i>>1;
				//for(p=0;p<k;p++){printf("[%d]",b[p]);}puts("");
				//printf("%d..",c2);
				for(j=0;j<=c2;j++)dp2[j]=0;
				
				dp2[0]=1;
				for(p=0;p<k;p++){
					for(j=c2;j>=b[p];j--){
						if(dp2[j-b[p]]&&!dp2[j]){
							dp2[j]=1;
							pd2[j]=p;
						}
					}
				}
				if(!dp2[i>>1]){
					for(j=0;j<n;j++)u[j]=0;
					
					continue;
				}
				for(j=0;j<k;j++)u2[j]=0;
				for(j=c2;j>0;j-=b[pd2[j]]){
					//printf("%d,%d ",j,b[pd2[j]]);
					
					u2[pd2[j]]=1;
				}
				puts("");
				for(i=0;i<n;i++){
					if(u[i])printf("%d ",a[i]);
				}
				puts("");
				
				
				
				
				for(i=0;i<n;i++){
					if(u2[i])printf("%d ",b[i]);
				}
				
				
				puts("");
				for(j=0;j<n;j++)u[j]=u2[j]=0;
				break;
			}
		}

		if(i<=2){
			puts("\nImpossible");
		}
		
	}
}
