#include<bits/stdc++.h>
using namespace std;
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RI64(x) scanf("%I64d",&(x))
#define RII64(x,y) scanf("%I64d%I64d",&(x),&(y))
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define pritnf printf
#define N 10514
using namespace std;
typedef long long int lnt;
typedef double dou;
int n;
char s[N];
int a[N];
int g[10][10]={
	{0,1,2,3,4,5,6,7},
	{1,4,3,6,5,0,7,2},
	{2,7,4,1,6,3,0,5},
	{3,2,5,4,7,6,1,0},
	//////////////////
	{0,1,2,3,4,5,6,7},
	{1,4,3,6,5,0,7,2},
	{2,7,4,1,6,3,0,5},
	{3,2,5,4,7,6,1,0}
};
int l[8][N];
int ggg[60][8];
lnt X;
int go(int x,lnt y){
	lnt u=y/n;
	for(int i=0;u;i++){
		if(u&1){
			x=ggg[i][x];
		}
		u/=2;
	}
	return l[x][y%n];
}
int test(){
	if(go(0,X*n)!=4)return 0;
	int l=-1;
	for(int i=1;i<X*n;i++){
		if(go(0,i)==1){
			l=i;
			break;
		}
	}
	if(l==-1)return 0;
	for(int i=l+1;i<X*n;i++){
		if(go(0,i)==3){
			return 1;
		}
	}
	return 0;
}
int test2(){
	if( X*n<3 || go(0,X*n)!=4 )return 0;
	int p=0;
	int l=-1;
	lnt ub;
	ub=min(X*n,10ll*n);
	for(int i=1;i<=ub;i++){
		p=g[p][ a[(i-1)%n+1] ];
		if(p==1){
			l=i;
			break;
		}
	}
	if(l==-1)return 0;
	ub=min(X*n,10ll*n+l+1);
	for(int i=l+1;i<=ub;i++){
		p=g[p][ a[(i-1)%n+1] ];
		if(p==3){
			return 1;
		}
	}
	return 0;
}
void sol(int uuu){
	RI(n);
	RI64(X);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[i]=( s[i]=='i'?1:( s[i]=='j'?2:3 ) );
	for(int j=0;j<8;j++){
		l[j][0]=j;
		for(int i=1;i<=n;i++)l[j][i]=g[ l[j][i-1] ][a[i]];
	}
	///////////////
	for(int j=0;j<8;j++){
		ggg[0][j]=l[j][n];
	}
	for(int i=1;i<60;i++){
		for(int j=0;j<8;j++){
			ggg[i][j]=ggg[i-1][ ggg[i-1][j] ];
		}
	}
	////////////////
	printf("Case #%d: %s\n",uuu,test2()?"YES":"NO");
}
int main(){
	for(int i=4;i<8;i++){
		for(int j=0;j<8;j++){
			g[i][j]=g[i^4][j]^4;
		}
	}
	freopen("C-large.in","r",stdin);
	freopen("Cout_l.txt","w",stdout);
	int t;RI(t);
	for(int i=1;i<=t;i++)sol(i);
	return 0;
}

