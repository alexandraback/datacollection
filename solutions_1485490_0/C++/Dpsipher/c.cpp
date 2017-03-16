#include "iostream"
#include "cstdio"
#include "vector"
#include "math.h"
#include "algorithm"
#include "string.h"
#include "sstream"
#include "stack"
#include "queue"
#include "map"
#define maX(a,b) ((a)>(b)?(a):(b))
#define miN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<(0)?(a)*(-1):(a))
#define pb(x) push_back(x)
#define pii pair<ll,ll>
#define ll long long
using namespace std;
//vector<pii> toy,box;
ll solve(ll n,ll m,vector<pii> box,vector<pii> toy)
{
	if(n==0||m==0)return 0ll;
	//ll & res=dp[n][m];
	if(toy[m].second==box[n].second){
		if(toy[m].first>box[n].first){
			toy[m].first-=box[n].first;
			ll res=box[n].first;
			box[n].first=0;
			return res+solve(n-1,m,box,toy);
		}
		else if(box[n].first>toy[m].first){
			box[n].first-=toy[m].first;
			ll res=toy[m].first;
			toy[m].first=0;
			return res+solve(n,m-1,box,toy);
		}
		else {
			return box[n].first+solve(n-1,m-1,box,toy);
		}
	}
	ll res1=solve(n-1,m,box,toy);
	ll res2=solve(n,m-1,box,toy);
	return maX(res1,res2);
}
int main()
{
	int test,tt;
	ll n,m,i,j;
	cin>>test;
	for(tt=1;tt<=test;tt++){
		printf("Case #%d: ",tt);
		cin>>n>>m;
		vector<pii> toy,box;
		box.resize(n+2);toy.resize(m+2);
		for(i=1;i<=n;i++){
			cin>>box[i].first>>box[i].second;
		}
		for(i=1;i<=m;i++)
			cin>>toy[i].first>>toy[i].second;
		cout<<solve(n,m,box,toy)<<endl;
	}
	return 0;
}
