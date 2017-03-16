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
int cnt[30];
int K,L,S;
char text[105];
char a[105];
double dy[105][105][105];
double ans=0.0;
int max=0;
char get[105];

void go(int x){
	if (x==S+1){
		int cnt2=0;
		//double prop=1.0;
		FOR (i,1,x-L+1){
			int flag=1;
			FOR (j,1,L) if (get[i+j-1]!=a[j]) flag=0;
			if (flag==1) cnt2++;
			//prop*=double(cnt[get[i]-'A'])/double(K);
		}
		max=MAX(max,cnt2);
		ans+=(double)cnt2;
		return;
	}
	FOR (i,1,K){
		get[x]=text[i];
		go(x+1);
	}
	get[x]=0;
}
int main(){
	int TT;
	si(TT);
	FOR (t,1,TT){
		si(K); si(L); si(S);
		fscanf(in,"%s",&text[1]);
		fscanf(in,"%s",&a[1]);
		ans=0.0;
		max=0;
		go(1);
		double temp=1.0;
		FOR (i,1,S) temp*=K;
		fprintf(out,"Case #%d: %.8lf\n",t,(double)max-ans/temp);
	}
	return 0;
}

		/*
		double max=0.0;
		int first=-1;
		FOR (i,2,L){
			int flag=0;
			FOR (j,1,L-i+1){
				if (a[i+j-1]!=a[j]) flag=1;
			}
			if (flag==0){ first=i; break; }
		}
		FOR (i,0,25) cnt[i]=0;
		FOR (i,1,K) cnt[text[i]-'A']++;
		int flag=0;
		FOR (i,1,L){
			if (cnt[a[i]-'A']==0) flag=1;
		}
		if (flag){
			fprintf(out,"Case #%d: 0.0\n",t);
			continue;
		}

		double prop1=1.0, prop2=0.0;
		FOR (i,1,L){
			prop1*=double(cnt[i])/double(K);
		}

		if (first!=-1){
			prop2=1.0;
			FOR (i,first,L){ prop2*=double(cnt[i])/double(K); }
			max=1+double((S-L)/(first-1));
		}else{
			max=(double)(S/L);
		}
		FOR (i,0,100) FOR (j,0,100) FOR (k,0,100) dy[i][j][k]=0.0;
		dy[0][0][0]=1.0;
		FOR (i,1,S){	
			FOR (j,0,S){

				FOR (k,0,L-1)
					if (a[k+1]==a[1]) dy[i][j][0]+=dy[i-1][j][k] * (1.0 - double(cnt[a[k+1]-'A'])/double(K));
					else dy[i][j][0]+=dy[i-1][j][k] * (1.0 - double(cnt[a[k+1]-'A'] + cnt[a[1]-'A'])/double(K));

				//dy[i][j][1] += dy[i-1][j][0] * double(cnt[a[1]-'A'])/double(K);
				FOR (k,1,L-1)
					if (a[k+1]==a[1]) continue;
					else dy[i][j][1] += dy[i-1][j][k] * double(cnt[a[1]-'A'])/double(K);

				FOR (k,1,L-1)
					dy[i][j][k] += dy[i-1][j][k-1] * double(cnt[a[k]-'A'])/double(K);

				if (j>=1){
					if (first==-1) dy[i][j][0] += dy[i-1][j-1][L-1] * double(cnt[a[L]-'A'])/double(K);
					else dy[i][j][L-first+1] += dy[i-1][j-1][L-1] * double(cnt[a[L]-'A'])/double(K);
				}
			}
		}
		FOR (j,1,S){
			FOR (k,0,L-1)
				max -= dy[S][j][k] * (double)j;
		}
		fprintf(out,"Case #%d: %.8lf\n",t,max);
	}
	return 0;
}*/