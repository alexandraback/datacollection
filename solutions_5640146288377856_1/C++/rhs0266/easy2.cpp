#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
typedef long long int T;
typedef double D;
typedef std::vector<int> vi;
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define si(n) fscanf(in,"%d",&n)
#define NM 500005
#define MOD 1000000007
#define INF 0x7fffffff
#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))
#define ABS(x) ((x>0)?(x):(-x))
#pragma warning (disable:4996)
//FILE *in=stdin,*out=stdout;
FILE *in=fopen("input.txt","r"),*out=fopen("output.txt","w");
int R,C,W;
int main(){
	int TT;
	si(TT);
	FOR (t,1,TT){
		si(R); si(C); si(W);
		int ans=0;
		ans=(R-1)*(C/W);
		while (C>=W*2){
			ans++;
			C-=W;
		}
		ans+=MIN(C,W+1);
		fprintf(out,"Case #%d: %d\n",t,ans);
	}
	return 0;
}