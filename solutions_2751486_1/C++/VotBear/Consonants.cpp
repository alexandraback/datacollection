#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cfloat>
#include<bitset>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
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
typedef vector<vi>                      vvi;
typedef vector<vl>                      vvl;

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
#define pf push_front
#define db pop_back
#define df pop_front
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

int n,t,l;
char inp[1000100];
bool cons(char c){
	if (!islower(c)||c=='e'||c=='a'||c=='i'||c=='u'||c=='o') return false;
	return true;
}
int main(){
    scanf("%d",&t);
    FORU(it,1,t+1){
		scanf("%s %d",inp,&n);
		printf("Case #%d: ",it);
		l=strlen(inp);
		int last=-1,ccnt=0;
		ll ans=0;
		FORU(i,0,l){
			if (cons(inp[i])) ++ccnt; else ccnt=0;
			if (ccnt>=n) last=i-n+1;
			//printf("%d %c cnt %d last %d\n",i,inp[i],ccnt,last);
			ans+=(max(0,last+1));
		}
		printf("%lld\n",ans);
	}
    return(0);
}
