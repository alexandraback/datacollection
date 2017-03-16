#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define eps 10e-8
#define N 1<<20
double dp[N],dps[N];

void init( int &n,int &m ){
	for( int i=0;i<n;++i ){
		scanf("%lf",dp+i);		
	}
	dps[0] = dp[0];
	for( int i=1;i<m;++i ) dps[i] = dp[i]*dps[i-1];
}

double clac( int n,int m,int k,bool s ){
	if( !s ){	
		return dps[n-k-1];
	}else{
		return 1.00 - dps[n-k-1];
	}
}

void solve( int n,int m ){
	double ret = m+1+1;
	for( int i=0;i<n;++i ){
		double cnt = clac(n,m,i,0)*(2*i+(m-n+1))+clac(n,m,i,1)*(2*i+(m-n+1)+(m+1));
		if( cnt - ret < 0.0 - eps ){
			ret = cnt;
			if( cnt < 0.0 - eps ) while(1);
		}
	}	
	double cnt = 1.00*(m+2);
	if( cnt - ret < 0.0 - eps ){
		ret = cnt;
	}
	printf("%.6lf\n",ret);
}

int main(){
	int t,n,m;
	//freopen("A-large.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d",&t);
	for( int _case = 0; _case < t; ++_case ){
		scanf("%d%d",&n,&m);
		init(n,m);
		printf("Case #%d: ",_case+1);
		solve(n,m);
	}
	return 0;
} 
/*
3
2 5
0.6 0.6
1 20
1
3 4
1 0.9 0.1
*/
