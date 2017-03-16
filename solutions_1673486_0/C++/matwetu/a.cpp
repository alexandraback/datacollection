/*a.cpp @ 2012年04月28日 09时10分53秒 BY dOMhOW*/
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

int main ( int argc, char *argv[] )
{
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		int a,b;long double p[100000];
		cin>>a>>b;
		for(int i=0;i<a;i++){
			cin>>p[i];
			p[i]=p[i]*(i?p[i-1]:1);
		}
		long double best=b+2;
		for(int i=0;i<a;i++){
			best=min(2*i+b-a+1+(1-p[a-i-1])*(b+1),best);
		}
		cout<<"Case #"<<t<<": ";
		printf("%.10f\n",double(best));

	}
	return EXIT_SUCCESS;
}

