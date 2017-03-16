/*a.cpp @ 2012年05月06日 00时06分14秒 BY dOMhOW*/
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
int n;
int s[3000000],from[3000000];
void print(int k){
	while(k){
		cout<<k-from[k]<<(from[k]?" ":"");
		k=from[k];
	}
	cout<<endl;
}
int main ( int argc, char *argv[] )
{
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;int tmp;
		CC(s,0);CC(from,-1);s[0]=1;
		cout<<"Case #"<<i<<":"<<endl;
		int done=0;
		for(int k=0;k<n;k++){
		cin>>tmp;
		for(int j=2000000;!done&&j>=tmp;j--){
			if(s[j-tmp]==1){
				if(s[j]==1){cout<<tmp<<" ";print(j-tmp);print(j);done=1;}
				else {from[j]=j-tmp;s[j]=1;}
			}
		}
		}
	}
	return EXIT_SUCCESS;
}

