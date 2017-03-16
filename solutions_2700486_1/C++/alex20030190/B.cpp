#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define LL long long
#define ERR 1E-11
using namespace std;
bool submit=true;
int t,n,x,y;
double dp[4003][4003];
int main(){
	if(submit){
		freopen("B-large.in.txt","r",stdin);
		freopen("B-large.out","w",stdout);
	}
	dp[0][0]=1.0;
	for(int i=1;i<=4000;i++){
		for(int j=0;j<=i;j++){
			if(j==0 || j==i) dp[i][j]=dp[i-1][0]/2;
			else dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])/2;
		}
	}
	
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d %d %d",&n,&x,&y);
		int L;
		for(L=1;L*(2*L-1)<n;L++);
		if((abs(x)+y)/2+1<L) printf("Case #%d: 1.0\n",i);
		else if((abs(x)+y)/2+1>L) printf("Case #%d: 0.0\n",i);
		else if(n==L*(2*L-1)) printf("Case #%d: 1.0\n",i);
		else if(x==0) printf("Case #%d: 0.0\n",i);
		else{
			int N=2*(L-1),R=n-(L-1)*(2*L-3),P=y+1;
			double Pos=0.0,T=0.0;
			for(int k=0;k<=N;k++){
				int j=R-k;
				if(j>=0 && j<=N){
					T+=dp[R][j];
					if(j>=P) Pos+=dp[R][j];
				}
			}
			printf("Case #%d: %.10lf\n",i,(Pos+.0)/T);
		}
	}
	return 0;
}
