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
int a[4][4]={{7,2,5,0},{6,7,0,1},{1,4,7,2},{0,1,2,3}};
int b[10][10];
int mae[11451],ato[11451];
int dec(char c){
	if(c=='i') return 0;
	if(c=='j') return 1;
	if(c=='k') return 2;
}
int zyo(int x,lint y){
	int ret=3;
	while(y>0){
		if(y%2>0) ret=b[ret][x];
		x=b[x][x];y/=2;
	}
	return ret;
}
int main()
{
	rep(i,4) rep(j,4) b[i][j]=a[i][j];
	rep(i,4) REP(j,4,8) b[i][j]=(4^a[i][j-4]);
	REP(i,4,8) rep(j,8) b[i][j]=(4^b[i-4][j]);
	int t;lint x,n;string s;
	cin>>t;
	rep(i,t){
		lint inf=1145141919810364364LL,imi=inf,kma=0;
		cin>>n>>x;cin>>s;
		mae[0]=ato[n]=3;
		rep(j,n) mae[j+1]=b[mae[j]][dec(s[j])];
		for(int j=n-1;j>=0;j--) ato[j]=b[dec(s[j])][ato[j+1]];
		if(zyo(mae[n],x)!=7){printf("Case #%d: NO\n",i+1);continue;}
		int now=3;
		rep(j,5){
			rep(k,n+1){
				if(b[now][mae[k]]==0) imi=min(imi,n*j+k);
				if(b[ato[k]][now]==2) kma=max(kma,n*x-(j+1)*n+k);
			}
			now=b[now][mae[n]];
		}
		//cout<<imi<<' '<<kma<<endl;
		if(kma>imi) printf("Case #%d: YES\n",i+1);
		else printf("Case #%d: NO\n",i+1);
	}
}
