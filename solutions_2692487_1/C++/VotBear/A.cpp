#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cfloat>
#include<bitset>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define Joshua using
#define ganteng namespace
#define sekali std
Joshua ganteng sekali;

typedef long long			ll;
typedef long double                     ld;
typedef pair<int,int>	  	        pi;
typedef pair<ll,ll>			pl;
typedef pair<double,double>	        pd;
typedef vector<int>			vi;
typedef vector<ll>			vl;
typedef vector<pi>			vii;
typedef vector<pl>			vll;
typedef vector<pd>			vdd;
typedef priority_queue<int>	        pq;

#define fi first
#define se second
#define pq priority_queue
#define SORT(a) sort(a.begin(),a.end())
#define DEBUG(a) printf("DEBUG %s\n",#a)
#define VALUE(a) printf("value of %s is %d\n",#a,a)
#define VALUELL(a) printf("value of %s is %lld\n",#a,a)
#define FORU(a,b,c) for(int a=b;a<c;++a)
#define FORD(a,b,c) for(int a=b-1;a>=c;--a)
#define MP(a,b) make_pair(a,b)
#define bikin_popcorn __builtin_popcount
#define iswhite(a) (a==' '||a=='\n')
#define pb push_back
#define db pop_back
#define PI 3.14159265
#define INF 100000000
#define MOD 1000
#define EPS 1E-9
#define MXN 1000
//#define getchar getchar_unlocked

template <class T> inline void getint(T &num)
{
	bool neg=0;
	num=0;
	char c;
	while ((c=getchar()) && (!isdigit(c) && c!='-'));
	if (c=='-'){
		neg=1;
		c=getchar();
	}
	do num=num*10+c-'0';
	while ((c=getchar()) && isdigit(c));
	num*=(neg)?-1:1;
}

int n,m,t;
ll a,siz[120];

int find(int dex,ll now){
	if(dex==n) return 0;
	if(siz[dex]<now) return find(dex+1,siz[dex]+now);
	else {
		int cnt=0;
		while(now<=siz[dex]){
			now=now*2-1;
			++cnt;
		}
		return(min(n-dex,cnt+find(dex+1,now+siz[dex])));
	}
}

int main(){
	getint(t);
	FORU(it,1,t+1){
		printf("Case #%d: ",it);
	    getint(a); getint(n);
		FORU(i,0,n) getint(siz[i]);
		sort(siz,siz+n);
		if(a==1) printf("%d\n",n);
		else {
			printf("%d\n",find(0,a));
		}
	}
	return(0);
}
