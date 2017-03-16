#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)


int main(void){
	int qn;
	scanf("%d",&qn);
	reg(qqq,1,qn){
		printf("Case #%d:",qqq);
		int s,k,c;
		scanf("%d%d%d",&k,&c,&s);
		if(k>c*s){
			puts(" IMPOSSIBLE");
			continue;
		}
		int d = (k+c-1)/c;
		rep(i,d){
			int to=min(i*c+c-1,k-1);
			int fr=max(0,to-c+1);
			lli su = 0,b = 1;
			reg(j,fr,to){
				su += (j*b);
				b*=k;
			}
			printf(" %lld",su+1);
		}
		printf("\n");
	}
	return 0;
}

/*
5
2 3 2
1 1 1
2 1 1
2 1 2
3 2 3
*/




