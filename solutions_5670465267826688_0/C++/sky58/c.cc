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
bool dp[11451][5];
int dec(char c){
	if(c=='i') return 0;
	if(c=='j') return 1;
	if(c=='k') return 2;
}
int main()
{
	rep(i,4) rep(j,4) b[i][j]=a[i][j];
	rep(i,4) REP(j,4,8) b[i][j]=(4^a[i][j-4]);
	REP(i,4,8) rep(j,8) b[i][j]=(4^b[i-4][j]);
	int n,t,x;string S;
	cin>>t;
	rep(i,t){
		cin>>n>>x;cin>>S;
		string s="";rep(j,x) s+=S;n*=x;
		//cout<<n<<s<<endl;
		memset(dp,false,sizeof(dp));dp[0][0]=true;
		rep(j,n) rep(k,3){
			if(!dp[j][k]) continue;
			//cout<<j<<' '<<k<<endl;
			int now=3;
			REP(l,j,n){
				//cout<<now<<dec(s[l])<<endl;
				now=b[now][dec(s[l])];
				//cout<<k<<' '<<l<<' '<<now<<endl;
				if(now==k) dp[l+1][k+1]=true;
			}
		}
		if(dp[n][3]) printf("Case #%d: YES\n",i+1);
		else printf("Case #%d: NO\n",i+1);
	}
}
