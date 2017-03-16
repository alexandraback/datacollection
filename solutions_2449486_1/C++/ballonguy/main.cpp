#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdio>
#include<string.h>
#include<set>
using namespace std;

typedef long long Int;
#define FOR(i,a,b)  for(int i=(a);i<=(b);++i)
#define sz(s) (int)(s).size()
#define mp make_pair
#define pb push_back
void assert(bool x){if(!x)throw -1;}
const int inf = 1000000000;
const int MOD = 1000000007;
#define sqr(x) (x)*(x)
const double PI = acos(-1.0);

int mxr[111],mxc[111],x[111][111];

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	//freopen("B-small-attempt0.in","r",stdin);freopen("output.txt","w",stdout);
	freopen("B-large.in","r",stdin);freopen("output.txt","w",stdout);
	int tests;scanf("%d\n",&tests);
	for(int test = 1; test <= tests; ++ test) {
		int n,m;
		cin>>n>>m;
		memset(mxr,0,sizeof(mxr));
		memset(mxc,0,sizeof(mxc));
		FOR(i,1,n)FOR(j,1,m){
			cin>>x[i][j];
			mxr[i]=max(mxr[i],x[i][j]);
			mxc[j]=max(mxc[j],x[i][j]);
		}
		bool can=true;
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)
			if(x[i][j]!=min(mxr[i],mxc[j]))can=false;
		cout<<"Case #"<<test<<": "<<(can?"YES":"NO")<<endl;
	}
}