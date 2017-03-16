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

int n,m,t,inp[120][120],mxx[120],mxy[120];
int main(){
    scanf("%d",&t);
    FORU(it,0,t){
		memset(mxx,0,sizeof mxx);
		memset(mxy,0,sizeof mxy);
		scanf("%d %d",&n,&m);
		FORU(i,0,n) FORU(j,0,m){
			scanf("%d",&inp[i][j]);
			mxx[i]=max(mxx[i],inp[i][j]);
			mxy[j]=max(mxy[j],inp[i][j]);
		}	
		bool can=true;
		FORU(i,0,n) FORU(j,0,m){
			if (inp[i][j]<mxx[i]&&inp[i][j]<mxy[j]){
				can=false;
				break;	
			}
		}
		printf("Case #%d: ",it+1);
		if (can) printf("YES\n"); else printf("NO\n");
	}
    return(0);
}
