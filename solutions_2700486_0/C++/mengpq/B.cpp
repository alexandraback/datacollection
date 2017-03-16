#include<cctype>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=128;
const int INF=0x3f3f3f3f;
const double eps=1e-8;

#define rep(i,st,ed) for (int i=st; i<ed; i++)

int n;
double x,y;
double f[MAXN][MAXN];

int C(int x){
	return (x+1)*x/2;
}

double solve(){
	x=fabs(x); y=fabs(y);
	int sum=x+y+1;
	if (C(sum)<=n) return 1;
	if (C(sum-2)>=n) return 0;

	int X=sum-1,Y=n-C(sum-2);

	f[0][0]=1;
	rep(i,0,X+1) rep(j,0,X+1) if (i+j<=y && (i || j)){
		f[i][j]=0;
		if (i){
			if (j==X) f[i][j]+=f[i-1][j]; else f[i][j]+=f[i-1][j]*0.5;
		}

		if (j){ 
			if (i==X) f[i][j]+=f[i][j-1]; else f[i][j]+=f[i][j-1]*0.5;
		}
	}

	double ret=0;
	for (int i=y+1; i<=sum-1; i++) 
		if ((Y-i>=0) && (Y-i<=sum-1)) ret+=f[i][Y-i];
	return ret;
}

void init(){
	cin>>n>>x>>y;
}

int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int ca;
	cin>>ca;
	rep(i,0,ca){
		init();
		printf("Case #%d: %.7lf\n",solve());
	}
	return 0;
}
