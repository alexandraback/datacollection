#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
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
int dp[(1<<20)+10];
int fir[25],op[25];
int key[25][25];
vector <int> next[(1<<20)+10];
int n;

int rec(int x){
	if(dp[x]>=0) return dp[x];
	if(x==(1<<n)-1) return dp[x]=1;
	int now[25];rep(i,21) now[i]=fir[i];
	rep(i,n){
		if(!(x&(1<<i))) continue;
		rep(j,21) now[j]+=key[i][j];
		now[op[i]]--;
	}
	//cout<<x<<' '<<now[1]<<' '<<now[2]<<' '<<now[3]<<endl;
	rep(i,n){
		if((x&(1<<i))) continue;
		if(now[op[i]]>0){
			next[x].pb(i);//cout<<x<<' '<<i<<endl;
			if(rec(x+(1<<i))>0) return dp[x]=1;
		}
	}
	return dp[x]=0;
}
int main()
{
	int t,k,a;cin>>t;
	rep(i,t){
		cout<<"Case #"<<i+1<<": ";
		memset(dp,-1,sizeof(dp));
		memset(fir,0,sizeof(fir));
		memset(key,0,sizeof(key));
		rep(j,(1<<20)) next[j].clear();
		cin>>k>>n;
		rep(j,k){
			cin>>a;fir[a]++;
		}
		rep(j,n){
			cin>>op[j];cin>>k;
			rep(l,k){
				cin>>a;key[j][a]++;
			}
		}
		if(rec(0)==0){cout<<"IMPOSSIBLE"<<endl;continue;}
		int f=0;
		while(1){
			rep(j,next[f].size()){
				int g=next[f][j];
				if(dp[f+(1<<g)]>0){
					cout<<g+1;f+=(1<<g);break;
				}
			}
			//cout<<f<<endl;
			if(f<(1<<n)-1) cout<<' ';else{cout<<endl;break;}
		}
	}
	return 0;
}
