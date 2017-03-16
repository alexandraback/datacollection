#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
double dp[2020][2020];

main(){
	int testcase;
	scanf("%d ",&testcase);
	for(int casenum=1;casenum<=testcase;casenum++){
		printf("Case #%d: ",casenum);
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		if(x<0)x=-x;
		int z=(x+y)/2;
		if(n<=2*z*z-z)printf("0.0\n");
		else if(n>=2*(z+1)*(z+1)-(z+1))printf("1.0\n");
		else{//Here, z=O(1000)
			int m=n-(2*z*z-z);
			memset(dp,0,sizeof(dp));
			dp[0][0]=1;
			for(int s=0;s<=4*z;s++){
				for(int j=0;j<=2*z;j++){
					int i=s-j;
					if(i<0||i>2*z)continue;
					if(i==2*z&&j==2*z)continue;
					else if(i==2*z)dp[i][j+1]+=dp[i][j];
					else if(j==2*z)dp[i+1][j]+=dp[i][j];
					else{dp[i+1][j]+=dp[i][j]/2;dp[i][j+1]+=dp[i][j]/2;}
				}
			}
			//for(int i=0;i<=2*z;i++){for(int j=0;j<=2*z;j++)printf("%.3f ",dp[i][j]);puts("");}
			double ans=0;
			for(int i=0;i<=2*z;i++){
				int j=m-i;
				if(j>=0&&j<=2*z){
					if(j>y)ans+=dp[i][j];
				}
			}
			printf("%.10f\n",ans);
		}
	}
}