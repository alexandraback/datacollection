#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<complex>
#define EPS (1e-10)
#define PI (3.141592653589793238)
#define MP make_pair
typedef long long ll;
using namespace std;

int n,s,p;
int total[200];
int dp[200][200];

bool sphigh,notsphigh,splow;

void check(int t){

	sphigh=notsphigh=splow=false;

	for(int i=0;i<=10;i++){
		for(int j=0;j<=10;j++){
			for(int k=0;k<=10;k++){
				if(i+j+k!=t)continue;
				int mi=min(i,min(j,k));
				int ma=max(i,max(j,k));
				if(ma-mi>=3)continue;
				if(ma-mi==2 && ma>=p)sphigh=true;
				if(ma-mi==2 && ma<p)splow=true;
				if(ma-mi<=1 && ma>=p)notsphigh=true;
			}
		}
	}

	return;
}

int main(void){
	int casenum;
	scanf("%d",&casenum);
	for(int casecnt=1;casecnt<=casenum;casecnt++){

		scanf("%d %d %d",&n,&s,&p);
		for(int i=0;i<n;i++){
			scanf("%d",&total[i]);
		}
		for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=-1000000;

		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			check(total[i-1]);
			for(int j=0;j<=n;j++){
				dp[i][j]=dp[i-1][j];
				if(sphigh){
					if(j>0)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
				}
				if(notsphigh){
					dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
				}
				if(splow){
					if(j>0)dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
				}
			}
		}

		printf("Case #%d: %d\n",casecnt,dp[n][s]);
		fflush(stdout);
	}
	return 0;
}
