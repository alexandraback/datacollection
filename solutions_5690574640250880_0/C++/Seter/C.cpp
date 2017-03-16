//Orz Sevenkplus
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<complex>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#define un using namespace
un std;
#define pb push_back
#define pf pop_front

#define mp make_pair

#define c0 first
#define c1 second
#define sqr(x)((x)*(x))
#define clr(x)memset(x,0,sizeof(x))
#define clr1(x)memset(x,-1,sizeof(x))
#define clr80(x)memset(x,0x80,sizeof(x))
#define clr7F(x)memset(x,0x7F,sizeof(x))

#define ll long long
#ifdef __unix__
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif
#define pii pair<int,int>
#define pip pair<int,pii>
#define vi vector<int>
#define vpi vector<pii>
#define pq priority_queue

template<typename T>inline bool chkmin(T&a,T b){return a>b?a=b,1:0;}
template<typename T>inline bool chkmax(T&a,T b){return a<b?a=b,1:0;}
#define modadd(a,b,c)(((a)+(b))%(c))
#define modmul(a,b,c)((int)(((ll)(a)*(b))%(c)))

#define P 1000000007


#define getint(x){\
	char __next__char__;bool __nega__int__=0;\
	while(!isdigit(__next__char__=getchar())&&__next__char__!='-');\
	__next__char__=='-'?(x=0,__nega__int__=1):(x=__next__char__-48);\
	while(isdigit(__next__char__=getchar()))x=x*10+__next__char__-48;\
	if(__nega__int__)x=-x;\
}
#define getint2(x1,x2){getint(x1);getint(x2);}
#define getint3(x1,x2,x3){getint(x1);getint(x2);getint(x3);}
#define getint4(x1,x2,x3,x4){getint(x1);getint(x2);getint(x3);getint(x4);}
#define getint5(x1,x2,x3,x4,x5){getint(x1);getint(x2);getint(x3);getint(x4);getint(x5);}
#define getint6(x1,x2,x3,x4,x5,x6){getint(x1);getint(x2);getint(x3);getint(x4);getint(x5);getint(x6);}


int n,m,k;
char a[50][51];

void Run(){
	scanf("%d%d%d",&n,&m,&k);
	if(n*m<=k){
		puts("Impossible");
		return;
	}
	if(n==1||m==1){
		putchar('c');
		if(m==1)putchar('\n');
		for(int i=n+m-2-k;i--;){
			putchar('.');
			if(m==1)putchar('\n');
		}
		while(k--){
			putchar('*');
			if(m==1)putchar('\n');
		}
		if(m!=1)putchar('\n');
		return;
	}
	if(n*m==k+1){
		putchar('c');
		for(int i=n;i--;){
			for(int j=m;j--;){
				if(i==n-1&&j==m-1)continue;
				putchar('*');
			}
			putchar('\n');
		}
		return;
	}
	k=n*m-k;
	for(int p=2;p<=m&&2*p<=k;p++){
		for(int q=2;q<=n&&2*p+2*q-4<=k;q++){
			if(p*q>=k){
				for(int i=n;i--;){
					for(int j=m;j--;)a[i][j]='*';
					a[i][m]=0;
				}
				for(int i=q;i--;)a[i][0]=a[i][1]='.';
				for(int i=p;i--;)a[0][i]=a[1][i]='.';
				if(p>2){
					int s=(k-(2*p+2*q-4))/(p-2);
					for(int i=s;i--;)
						for(int j=p-2;j--;)a[2+i][j+2]='.';
					for(int j=(k-(2*p+2*q-4))%(p-2);j--;)a[2+s][j+2]='.';
				}
				a[0][0]='c';
				
				for(int i=-1;++i!=n;){
					puts(a[i]);
				}
				return;
			}
		}
	}
	puts("Impossible");
}

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		printf("Case #%d:\n",t);
		Run();
	}
	return 0;
}
