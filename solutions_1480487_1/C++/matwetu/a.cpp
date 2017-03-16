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

int n,p[300],mark[300],fst=-1,snd=-1,sum=0;
int ok(int k,double pc){
	double left=1-pc,aim=p[k]+pc*sum;
	for(int i=0;i<n;i++){
		if(i!=k){
			if(p[i]>aim)continue;
			if(p[i]+sum*left<=aim)return 1;
			left-=(aim-p[i])/sum;
		}
	}
	return 0;
}
double get(int k){
	double  l=0,r=1;
	for(int i=0;i<100;i++){
		double md=(l+r)/2;
		if(ok(k,md))r=md;
		else l=md;
	}
	return (l+r)/2*100;
}
int main ( int argc, char *argv[] )
{
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		CC(mark,0);sum=0;
		for(int j=0;j<n;j++){
			cin>>p[j];
			sum+=p[j];
		}
		cout<<"Case #"<<i<<":";
		cout.precision(10);
		for(int j=0;j<n;j++){
			printf(" %.10f",get(j));
		}
		cout<<endl;
	}
	return EXIT_SUCCESS;
}

