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
double co[4010][4010];
int main()
{
	rep(i,4010) rep(j,4010) co[i][j]=0.0;co[0][0]=1.0;
	REP(i,1,4005) rep(j,i+1){
		if(j>0) co[i][j]+=0.5*co[i-1][j-1];co[i][j]+=0.5*co[i-1][j];
	}
	int n,m,x,y,t;
	cin>>t;
	rep(i,t){
		cin>>n>>x>>y;x=abs(x);
		for(m=0;m*4+1<=n;m++) n-=m*4+1;
		if(x+y>2*m || (x+y==2*m && (n==0 || y==2*m))){
			printf("Case #%d: %.12f\n",i+1,0.0);continue;
		}
		if(x+y<2*m || (x+y==2*m && n==4*m)){
			printf("Case #%d: %.12f\n",i+1,1.0);continue;
		}
		double ret=0.0;
		REP(j,y+1,2*m){
			if(j+2*m-1<n) continue;
			//cout<<j<<' '<<n-j<<endl;
			ret+=co[n][j];
		}
		//cout<<ret<<endl;
		rep(j,n-2*m+1) ret+=0.5*co[2*m-1+j][j];
		//cout<<ret<<endl;
		if(y+1+2*m<=n) rep(j,n-2*m+1) ret+=0.5*co[2*m-1+j][j];
		printf("Case #%d: %.12f\n",i+1,ret);
	}
	return 0;
}
