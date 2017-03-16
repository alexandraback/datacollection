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
int x,n,m;
bool pro(){
	if (x==4){
		if (n*m==12) return true;
		if (n*m==16) return true;
		return false;
	}
	if (x==1) return true;
	if (x==2) return (n*m)%2==0;
	if (x==3){
		if ((n*m)%3!=0) return false;
		if (n%3!=0) std::swap(n,m);
		return m>=2;
	}
}
int main(){
	int T;
	si(T);
	FOR (t,1,T){
		si(x); si(n); si(m);
		fprintf(out,"Case #%d: ",t);
		if (pro()) fprintf(out,"GABRIEL\n");
		else fprintf(out,"RICHARD\n");
	}
	return 0;
}