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
T X,n;
char A[10005];
int a[10005];
int left,right;
int map[5][5]={{0,},{0,1,2,3,4},{0,2,1,4,3},{0,3,4,1,2},{0,4,3,2,1}};
int sig[5][5]={{0,},{0,1,1,1,1},{0,1,-1,1,-1},{0,1,-1,-1,1},{0,1,1,-1,-1}};
int sign,whole;

void mul(int *a,int *b,int c){
	int t=*b;
	*b=map[t][c];
	(*a)*=sig[t][c];
}
void mul2(int *a,int *b,int c){
	int t=*b;
	*b=map[c][t];
	(*a)*=sig[c][t];
}
void pro(){
	whole=1; sign=1;
	for (int i=1;i<=n;i++){
		int t=whole;
		mul(&sign,&whole,a[i]);
	}
	int s=1,cnt=1;
	T use1=INF,use2=INF;
	for (T i=1;i<=n;i++){
		mul(&s,&cnt,a[i]);
		int s2=s,cnt2=cnt;
		for (T j=0;j<=3;j++){
			if (s2==1 && cnt2==2){
				use1=MIN(use1,i+n*j);
				break;
			}
			s2*=sign;
			mul2(&s2,&cnt2,whole);
		}
	}
	s=cnt=1;
	for (T i=n;i>=1;i--){
		mul2(&s,&cnt,a[i]);
		int s2=s,cnt2=cnt;
		for (T j=0;j<=3;j++){
			if (s2==1 && cnt2==4){
				use2=MIN(use2,(n-i+1)+n*j);
				break;
			}
			s2*=sign;
			mul(&s2,&cnt2,whole);
		}
	}
	if (use1==INF || use2==INF) { fprintf(out,"NO\n"); return; }
	if (use2+use1>=n*X){ fprintf(out,"NO\n"); return; }
	s=cnt=1;
	for (int i=1;i<=X%4;i++){
		s*=sign;
		mul(&s,&cnt,whole);
	}
	if (s==-1 && cnt==1){ fprintf(out,"YES\n"); return; }
	fprintf(out,"NO\n");
}

int main(){
	int t;
	si(t);
	FOR (i,1,t){
		fscanf(in,"%lld %lld",&n,&X);
		fscanf(in,"%s",&A[1]);
		FOR (j,1,n){
			if (A[j]=='i') a[j]=2;
			if (A[j]=='j') a[j]=3;
			if (A[j]=='k') a[j]=4;
		}
		fprintf(out,"Case #%d: ",i);
		pro();
	}
	return 0;
}