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

int n,r,c,m;

void onemine(){
	printf("c");
	FORU(j,1,c) printf("*"); puts("");
	FORU(i,1,r){
		FORU(j,0,c) printf("*");
		puts("");
	}
	return;
}

void onerc(){
	int mn=0;
	int sp=r*c-m;
	FORU(i,0,r){
		FORU(i,0,c){
			if (mn>=sp) printf("*");
			else if (mn>0) printf(".");
			else printf("c");
			++mn;
		}
		printf("\n");
	}
}

vi spaces;

int genrow(int row,int prev,int left){
	if (left==0) return 1;
	else if (left==1||row>=r) return 0;
	FORD(i,prev+1,2){
		if (i>left) continue;
		spaces[row]=i;
		int t=genrow(row+1,i,left-i);
		if (t>0) return t;
	}
	spaces[row]=0;
	return 0;
}

void printmap(){
	FORU(i,0,r){
		FORU(j,0,c){
			if (i==0&&j==0) printf("c");
			else if (j<spaces[i]) printf(".");
			else printf("*");
		}
		printf("\n");
	}
}

void find(){
	int spc=r*c-m;
	
	spaces.clear();
	FORU(i,0,r) spaces.pb(0);
	
	FORD(i,c+1,2){
		if (2*i>spc) continue;
		spaces[0]=i;
		spaces[1]=i;
		if (genrow(2,i,spc-2*i)>0){
			printmap();
			return;
		}
	}
	printf("Impossible\n");
}

int main(){
    scanf("%d",&n);
    FORU(it,0,n){
    	scanf("%d %d %d",&r,&c,&m);
		printf("Case #%d:\n",it+1);
		if (r*c-m==1){
			onemine();
		} else if (r==1||c==1){
			onerc();
		} else {
			find();
		}
	}
    return(0);
}

