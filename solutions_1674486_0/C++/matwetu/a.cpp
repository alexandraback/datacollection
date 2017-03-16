/*a.cpp @ 2012年05月06日 16时50分44秒 BY dOMhOW*/
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
#define fori(i,n) for(int i=0;i<(int)n;i++)

typedef long long  LL;
int n;
int m[1001][1001],f[1001][1001];
int count(int x,int y){
	if(f[x][y]>=0)return f[x][y];
	f[x][y]=m[x][y];
	fori(i,n){
		if(m[x][i]&&i!=y){
			f[x][y]+=count(i,y);
		}
	}
	return f[x][y]=min(f[x][y],2);
}
int main ( int argc, char *argv[] )
{
	int t;cin>>t;
	fori(cas,t){
		cin>>n;
		CC(m,0);CC(f,-1);
		fori(i,n){
			int x,y;
			cin>>x;
			fori(j,x){
				cin>>y;m[i][y-1]=1;
			}
		}
		fori(i,n)fori(j,n)count(i,j);
		int ok=0;
		fori(i,n)fori(j,n)if(i!=j&&f[i][j]>1)ok=1;
		cout<<"Case #"<<cas+1<<": "<<(ok?"Yes":"No")<<endl;
	}
	return EXIT_SUCCESS;
}

