#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
typedef long long int T;
typedef double D;
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define si(n) fscanf(in,"%d",&n)
#define NM 500005
#define MOD 1000000007
#define INF 0x7fffffff
#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))
#define ABS(x) ((x>0)?(x):(-x))
#pragma warning (disable:4996)
typedef std::vector<int> vi;
//FILE *in=stdin,*out=stdout;
FILE *in=fopen("input.txt","r"),*out=fopen("output.txt","w");
int n,a[1005];
int ans;
void pro(){
	FOR (cut,1,1000){
		int t=0;
		FOR (i,1,n){
			t+=(a[i]-1)/cut;
		}
		ans=MIN(ans,t+cut);
	}
	fprintf(out,"%d\n",ans);
}
int main(){
	int T;
	si(T);
	FOR (t,1,T){
		si(n);
		FOR (i,1,n) si(a[i]);
		ans=0x7fffffff;
		fprintf(out,"Case #%d: ",t);
		pro();
	}
	return 0;
}