/*a.cpp @ 2013/04/13 11:27:29 BY dOMhOW*/
#include	<cstdlib>
#include	<cstdio>
#include	<cstring>
#include	<cmath>
#include	<map>
#include	<algorithm>
#include	<vector>
#include	<set>
#include	<queue>
#include	<iostream>
#include	<sstream>
#include	<string>
using namespace std;
#define CC(x,i) do{memset(x,i,sizeof(x));}while(0)
#define inf 0x7f7f7f7f
#define PII pair<int,int>
#define VI vector<int>
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(),x.end()
#define uniq(x) do{sort(all(x));x.resize(unique(all(x))-x.begin());}while(0)
#define two(x) (1ll<<(x))
#define forn(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define rep(i,x) for(int i=0;i<(int)(x);i++)

typedef long long  LL;
int h[111][111];
int main ( int argc, char *argv[] )
{
	int T;cin>>T;
	for(int cas=1;cas<=T;cas++){
	cout<<"Case #"<<cas<<": ";
	int m,n;
	cin>>m>>n;
	rep(i,m)rep(j,n){cin>>h[i][j];}
	bool flag=true;
	rep(i,m)rep(j,n){
		bool g=true,f=true;
		rep(k,m){
			if(h[k][j]>h[i][j])g=false;
		}
		rep(k,n){
			if(h[i][k]>h[i][j])f=false;
		}
		flag=flag&&(g||f);
	}
	cout<<(flag?"YES":"NO")<<endl;
	}
	return EXIT_SUCCESS;
}

