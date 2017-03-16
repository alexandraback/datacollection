#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define LL long long
#define ERR 1E-11
using namespace std;
bool submit=true;
int t,n,x,y;
double dp[3002][3002];
int T,Pos;
void exh(int L,int R,int Cap,int rem,int aim){
	if(L>Cap || R>Cap) return;
	if(rem==0){
		T++;
		if(L>=aim) Pos++;
		return;
	}
	exh(L+1,R,Cap,rem-1,aim);
	exh(L,R+1,Cap,rem-1,aim);
	return;
}
int main(){
	if(submit){
		freopen("B-small-attempt3.in.txt","r",stdin);
		freopen("B-small-attempt3.out","w",stdout);
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
			T=Pos=0;
			exh(0,0,N,R,P);
			/*dp[0][0]=1.0;
			for(int k=0;k<=R;k++){
				for(int j=0;j<=R;j++){
					if(k==0 && j==0) dp[0][0]=1.0;
					else if(k==0) dp[0][j]=dp[0][j-1]/2;
					else if(j==0) dp[k][0]=dp[k-1][0]/2;
					else dp[k][j]=(dp[k-1][j]+dp[k][j-1])/2;
				}
			}
			double ans=0.0,poss=0.0;
			for(int k=N;k>=0;k--){
				int j=R-k;
				if(j>=0 && j<=N) poss+=dp[k][j];
				if((j>=0 && j<=N) && k>=P) ans+=dp[k][j];
			}*/
			printf("Case #%d: %.8lf\n",i,(Pos+.0)/T);
		}
	}
	return 0;
}
