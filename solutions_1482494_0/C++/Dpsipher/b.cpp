#include"iostream"
#include"cstdio"
#include"vector"
#include"math.h"
#include"algorithm"
#include"string.h"
#include"sstream"
#include"stack"
#include"queue"
#include"map"
#define ll long long
#define maX(a, b) ((a) >= (b) ? (a) : (b))
#define miN(a, b) ((a) <= (b) ? (a) : (b))
#define ABS(a) ((a) < (0) ? (a)*(-1) : (a))
#define pb(x) push_back(x)
#define pii pair<ll,ll>
#define inf 1<<30
#define N 15
using namespace std;
int n;
vector<pii> A(N); 
vector< pair<bool,bool> > complete(N);
ll dp[1<<22];
ll solve(int star)
{
	ll i,f=0,res=inf,pw=1ll,st1=0,st2=0;
	for(i=0;i<n;i++){
		if(!complete[i].second){
			f=1;
		}
		st1=st1+pw*(int)(complete[i].first);
		st2=st2+pw*(int)(complete[i].second);
		pw*=2ll;
	}
	ll st=st2*pw+st1;
	if(dp[st]!=-1)return dp[st];
	//cout<<star<<endl;
	if(!f)return 0;
	for(i=0;i<n;i++){
		if(!complete[i].first && A[i].first<= star ){
			complete[i].first=true;
			res=miN(res,solve(star+1));
			complete[i].first=false;
		}
		if(!complete[i].second && A[i].second<=star){
			complete[i].second=true;
			if(!complete[i].first){
				res=miN(res,solve(star+2));
			}
			else{
				res=miN(res,solve(star+1));
			}
			complete[i].second=false;
		}
	}
	if(res!=inf)res++;
	dp[st]=res;
	return res;
}		
int main()
{
	ll i,t,tt,res;
	cin>>t;
	for(tt=1;tt<=t;tt++){
		memset(dp,-1,sizeof dp);
		A.clear();
		complete.clear();
		printf("Case #%lld: ",tt);
		cin>>n;
		for(i=0;i<n;i++){
			cin>>A[i].first>>A[i].second;
		}
		res=solve(0);
		if(res==inf){
			cout<<"Too Bad\n";
		}
		else{
			cout<<res<<endl;
		}
	}
	return 0;
}

