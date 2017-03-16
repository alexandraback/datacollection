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

int n,t,l,x,y; 
vector<char> ans;
int main(){
    scanf("%d",&t);
    FORU(it,1,t+1){
		scanf("%d %d",&x,&y);
		int tot=2*(abs(x)+abs(y));
		int lo=0,hi=tot;
		FORU(piv,1,tot){
			int needx=x,needy=y;
			vector<char> tans;
			FORD(i,piv+1,1){
				if (abs(needx)>abs(needy)){
					if (needx<0) {
						needx+=i;
						tans.pb('W');
					} else {
						needx-=i;
						tans.pb('E');
					}
				} else {
					if (needy<0) {
						needy+=i;
						tans.pb('S');
					} else {
						needy-=i;
						tans.pb('N');
					}
				}
			}
				if (needx==0&&needy==0){
					ans=tans;					
					break;
				} 
		}
		printf("Case #%d: ",it);
		FORD(i,ans.size(),0) printf("%c",ans[i]);
		puts("");
	}
    return(0);
} 
