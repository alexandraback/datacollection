#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
double dp[22][10][10][10];
int main()
{
	rep(i,22) rep(j,10) rep(k,10) rep(l,10) dp[i][j][k][l]=0.0;
	dp[0][0][0][0]=1.0;
	rep(i,22) rep(j,10) rep(k,10) rep(l,10){
		if(dp[i][j][k][l]<1e-13) continue;
		if(k==2*j && l==2*j) dp[i+1][j+1][0][0]+=dp[i][j][k][l];
		else if(k==2*j) dp[i+1][j][k][l+1]+=dp[i][j][k][l];
		else if(l==2*j) dp[i+1][j][k+1][l]+=dp[i][j][k][l];
		else{
			dp[i+1][j][k][l+1]+=0.5*dp[i][j][k][l];
			dp[i+1][j][k+1][l]+=0.5*dp[i][j][k][l];
		}
	}
	int n,m,x,y,t;
	cin>>t;
	rep(i,t){
		cin>>n>>x>>y;x=abs(x);double ret=0.0;
		rep(j,10) rep(k,10) rep(l,10){
			if(j*2>x+y || (j*2==x+y && k>y)) ret+=dp[n][j][k][l];
		}
		printf("Case #%d: %.12f\n",i+1,ret);
	}
	return 0;
}
