#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
long long t[521196];
char str[4001];
int dp[4001][5];
int main(){
	freopen("garbled_email_dictionary.txt","r",stdin);
	for(int i=0;i<521196;i++){
		scanf("%s",str);
		for(int j=0;str[j];j++){
			t[i]<<=5;
			t[i]+=str[j]-'a'+1;
		}
	}
	std::sort(t,t+521196);
	freopen("in.txt","r",stdin);
	int a;
	scanf("%d",&a);
	for(int T=1;T<=a;T++){
		scanf("%s",str);
		int n=strlen(str);
		for(int i=0;i<4001;i++)
			for(int j=0;j<5;j++)
				dp[i][j]=99999999;
		dp[0][0]=0;
		for(int i=0;i<n;i++){
		//	printf("\n");
			for(int j=0;j<5;j++){
		//		printf("%d ",dp[i][j]);
				if(dp[i][j]==99999999)continue;
				for(int k=j;k<10;k++){
					for(int l=k+5;l<10;l++){
						for(char p='a';p<='z';p++){
							for(char q='a';q<='z';q++){
								long long val=0;
								int count=2;
								for(int r=0;r<10&&i+r<n;r++){
									char V=str[i+r];
									
									if(r==k){V=p;}
									if(r==l){V=q;}
									val<<=5;
									val+=V-'a'+1;
									if(binary_search(t,t+521196,val)){
								//		printf("%lld\n",val);
										dp[i+r+1][min(4,l-r+4)]=min(dp[i+r+1][min(4,l-r+4)],dp[i][j]+count);
									}
								}
							}
						}
					}
				}
				for(int k=j;k<10;k++){
					for(char p='a';p<='z';p++){
						long long val=0;
						int count=1;
						for(int r=0;r<10&&i+r<n;r++){
							char V=str[i+r];
							
							if(r==k){V=p;}
							val<<=5;
							val+=V-'a'+1;
							if(binary_search(t,t+521196,val)){
						//		printf("%lld\n",val);
								dp[i+r+1][min(4,max(0,k-r+4))]=min(dp[i+r+1][min(4,max(0,k-r+4))],dp[i][j]+count);
							}
						}
					}
				}
				long long val=0;
				//int count=0;
				for(int r=0;r<10&&i+r<n;r++){
					char V=str[i+r];
					val<<=5;
					val+=V-'a'+1;
					if(binary_search(t,t+521196,val)){
				//		printf("%lld\n",val);
						dp[i+r+1][max(0,j-r)]=min(dp[i+r+1][max(0,j-r)],dp[i][j]);
					}
				}
			}
		}
		int ret=999999999;
		for(int i=0;i<5;i++)ret=min(ret,dp[n][i]);
		printf("Case #%d: %d\n",T,ret);
	}
}