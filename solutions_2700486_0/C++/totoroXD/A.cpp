#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n, x, y,cnt=0, dp[1111][1111];
int c(int n, int m){
	if(m<0 || n<m)return 0;
	else if(m==0)return 1;
	else if(dp[n][m]!=-1)return dp[n][m];
	dp[n][m] = c(n-1,m)+c(n-1,m-1);
	return dp[n][m];
}
void input(){
	cin>>n>>x>>y;
}
void solve(){
	x = abs(x);
	int l = sqrt(n+3)-1, r;
	r = n-((l+1)*(l+1)-3);
	double res;
	if((x-y)%2)
		res=0;
	else if(x+y<l*2)
		res=1;
	else if((l+1)*2<x+y){
		res=0;
	}
	else{
		int d = (2*l-x)+1;
		//printf("l = %d, r = %d, d = %d\n",l,r,d);
		res=1.1;
		if(x==0){
			res=0;
		}
		else if(r<=l+1){
			res=0;
			for(int i=d; i<=r; i++)
				res+= c(r, i);
			res/=pow(2,r);
		}
		else{
			res=0;
			for(int i=d; i<=r; i++){
				if(i<=l+1 && r-i<=l+1){
					res+= c(r, i);
					//printf("C %d %d\n",r,i);
				}
			}
				for(int i=l+1+1; i<=r; i++){
					res+= c(r, i);
					if(d<=r-(l+1))
						res+= c(r, i);
					//printf("C %d %d\n",r,i);
				}
			res/=pow(2,r);
		}
	}
	printf("Case #%d: %lf\n",++cnt, res);
}
int main ()
{
	freopen("B-small-attempt4.in", "r",stdin);
	freopen("B-small-attempt4.out","w", stdout);
	memset(dp,-1,sizeof(dp));
	int zz;
	cin>>zz;
	while(zz--){
		input();
		solve();
	}
	return 0;
}

/*
100
19 -3 3
4 0 2
5 0 2
*/
