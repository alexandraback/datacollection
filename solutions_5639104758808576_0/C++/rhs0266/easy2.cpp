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
char a[1005];
int n;
int ans;
void pro(int N){
	fprintf(out,"Case #%d: ",N);
	ans=0;
	int t=0;
	for (int i=0;i<=n;i++){
		if (a[i]=='0') continue;
		if (t<i) ans+=i-t,t=i;
		t+=(a[i]-'0');
	}
	fprintf(out,"%d\n",ans);
}
int main(){
	int T;
	fscanf(in,"%d",&T);
	for (int i=1;i<=T;i++){
		fscanf(in,"%d %s",&n,a);
		pro(i);
	}
	return 0;
}