/*Q3.cpp @ 2012年04月14日 14时17分15秒 BY dOMhOW*/
/* 
 * status : AC  WA  TLE
 */
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<math.h>
#include	<map>
#include	<algorithm>
#include	<vector>
#include	<set>
#include	<iostream>
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
typedef long long  LL;
bool mark[2100000];
int w=0,t,ans,A,B;
void gao(int x)
{
	mark[x]=true;
	int c=1;
	for(int i=0;i<w;i++){
		x=x/t+x%t*10;
		if(x>=A&&x<=B&&!mark[x]){
			mark[x]=true;
			c++;
		}
	}
/*	if(c>1){
		cout<<"got "<<c*(c-1)/2<<" at "<<x<<endl;
	}*/
	ans+=c*(c-1)/2;
}
int main ( int argc, char *argv[] )
{
	int T;cin>>T;
	for(int i=1;i<=T;i++){
		CC(mark,0);
		cin>>A>>B;w=0;t=1;
		int tmp=A;while(tmp){
			tmp/=10;w++;t*=10;
		};
		t/=10;ans=0;
		for(int j=A;j<=B;j++){
			if(!mark[j])gao(j);
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return EXIT_SUCCESS;
}

