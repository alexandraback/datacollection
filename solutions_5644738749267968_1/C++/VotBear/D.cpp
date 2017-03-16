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
#define is namespace
#define awesome std
Joshua is awesome;

typedef long long			ll;
typedef long double         ld;
typedef pair<int,int>       pi;
typedef pair<ll,ll>         pl;
typedef pair<double,double> pd;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef vector<pi>          vii;
typedef vector<pl>          vll;
typedef vector<pd>          vdd;
typedef vector<vi>          vvi;
typedef vector<vl>          vvl;

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

int n,tt;
double t;
vector<double> a,b;

int dec(){
	int cnt=0;
	int ita=0;
	while (cnt<n&&ita<n){
		while (ita<n&&a[ita]<b[cnt]){
			++ita;
		}
		if (ita<n&&a[ita]>b[cnt]){
			++cnt;
			++ita;
		}
	}
	return cnt;
}

int war(){
	int ret=0;
	int ita=n-1, itb=n-1;
	while (ita>=0){
		//printf("%lf %lf\n",a[ita],b[itb]);
		if (a[ita]>b[itb]) ++ret;
		else --itb;
		--ita;
	}
	return ret;
}

int war2(){
	int ret=n;
	int ita=0, itb=0;
	while (itb<n&&ita<n){
		//printf("%lf %lf\n",a[ita],b[itb]);
		while (itb<n&&a[ita]>b[itb]) ++itb;
		if (itb<n&&b[itb]>a[ita]){
			++ita;
			++itb;
			--ret;
		}
	}
	return ret;
}

int main(){
	scanf("%d",&tt);
	FORU(it,0,tt){
		a.clear();
		b.clear();
	    scanf("%d",&n);
	    FORU(i,0,n){
	    	scanf("%lf",&t);
	    	a.pb(t);
		}
	    FORU(j,0,n){
	    	scanf("%lf",&t);
	    	b.pb(t);
	    }
	    sort(a.begin(),a.end());
	    sort(b.begin(),b.end());
		
	    //FORU(i,0,a.size()) printf("%.3lf ",a[i]); puts("");
	    //FORU(i,0,b.size()) printf("%.3lf ",b[i]); puts("");
		printf("Case #%d: %d %d\n",it+1,dec(),war());
		//printf("%d %d %s\n",war(),war2(), war()==war2()?"":"ALERT ALERT ALERT");
		//puts("");
	}
    return(0);
}

