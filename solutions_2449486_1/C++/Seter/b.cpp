//Orz Sevenkplus
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<complex>
#include<algorithm>
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

template<typename T>inline bool chkmin(T&a,T&b){return a>b?a=b,1:0;}
template<typename T>inline bool chkmax(T&a,T&b){return a<b?a=b,1:0;}
#define modadd(a,b,c)(((a)+(b))%(c))
#define modmul(a,b,c)((int)(((ll)(a)*(b))%(c)))

#define P 1000000007


#define getint(x){\
	char __next__char__;\
	while(!isdigit(__next__char__=getchar()));x=__next__char__-48;\
	while(isdigit(__next__char__=getchar()))x=x*10+__next__char__-48;\
}
#define getint2(x1,x2){getint(x1);getint(x2);}
#define getint3(x1,x2,x3){getint(x1);getint(x2);getint(x3);}
#define getint4(x1,x2,x3,x4){getint(x1);getint(x2);getint(x3);getint(x4);}
#define getint5(x1,x2,x3,x4,x5){getint(x1);getint(x2);getint(x3);getint(x4);getint(x5);}
#define getint6(x1,x2,x3,x4,x5,x6){getint(x1);getint(x2);getint(x3);getint(x4);getint(x5);getint(x6);}

bool run(){
	int n,m;
	getint2(n,m);
	static int a[100][100],f[100][100];
	for(int i=-1;++i!=n;)for(int j=-1;++j!=m;f[i][j]=100)getint(a[i][j]);
	while(1){
		bool c=0;
		for(int i=-1;++i!=n;){
			int x=*max_element(a[i],a[i]+m);
			int y=*max_element(f[i],f[i]+m);
			if(x==y)continue;
			c=1;
			for(int j=-1;++j!=m;)if(f[i][j]>x)f[i][j]=x;
		}
		for(int j=-1;++j!=m;){
			int x=0,y=0;
			for(int i=-1;++i!=n;)x=max(x,a[i][j]),y=max(y,f[i][j]);
			if(x==y)continue;
			c=1;
			for(int i=-1;++i!=n;)if(f[i][j]>x)f[i][j]=x;
		}
		if(!c){
			for(int i=-1;++i!=n;)
			for(int j=-1;++j!=m;)if(a[i][j]!=f[i][j])return 0;
			return 1;
		}
	}
}

int main(){
	int t;
	getint(t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: %s\n",i,run()?"YES":"NO");
	}
	return 0;
}
