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
	{3,2,5,4,7,6,1,0},
	{3,2,5,4,7,6,1,0},
	{3,2,5,4,7,6,1,0},
	{3,2,5,4,7,6,1,0}
};
int l[N];
int r[N];
int test(){
	for(int i=1;i<=n;i++){
		int p=0;
		for(int j=i;j<=n;j++){
			p=g[p][a[j]];
			if(l[i-1]==1&&p==2&&r[j+1]==3){
				return 1;
			}
		}
	}
	return 0;
}
lnt X;
void sol(int uuu){
	RI(n);
	RI64(X);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[i]=( s[i]=='i'?1:( s[i]=='j'?2:3 ) );
	for(int i=1;i<X;i++){
		for(int j=1;j<=n;j++){
			a[i*n+j]=a[j];
		}
	}
	n*=X;
	l[0]=0;
	for(int i=1;i<=n;i++){
		l[i]=g[l[i-1]][a[i]];
	}
	r[n+1]=0;
	for(int i=n;i>=1;i--){
		r[i]=g[a[i]][r[i+1]];
	}
	printf("Case #%d: %s\n",uuu,test()?"YES":"NO");
}
int main(){
	for(int i=4;i<8;i++){
		for(int j=0;j<8;j++){
			g[i][j]=g[i^4][j]^4;
		}
	}
	freopen("C-small-attempt0.in","r",stdin);
	freopen("Cout_s.txt","w",stdout);
	int t;RI(t);
	for(int i=1;i<=t;i++)sol(i);
	return 0;
}

