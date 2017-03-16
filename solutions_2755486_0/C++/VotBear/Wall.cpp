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
#define MXN 1000000
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

struct enemy{
	int day,atk,st,ed,hgt,dday,dmov,dhgt;
	enemy(){} 
	enemy(int a,int b,int c,int d,int e,int f,int g,int h){
		day=a;
		atk=b;
		st=c;
		ed=d;
		hgt=e;
		dday=f;
		dmov=g;
		dhgt=h;
	}
	bool operator < (enemy a) const{
		return day>a.day;
	}
};
int t,n,a,b,c,d,e,f,g,h;
int tree[4*4100000];

bool query(int nod,int st,int ed,int qst,int qed,int val){ 
	if(st>=ed){
		return (tree[nod]<val);
	} else if (qst<=st&&qed>=ed){
		return (tree[nod]<val);
	} else {
		int piv=(st+ed)/2;
		if (qed<=piv){
			return (query(nod*2,st,piv,qst,qed,val)); 
		} else if (qst>piv){
			return (query(nod*2+1,piv+1,ed,qst,qed,val)); 
		} else {
			return (query(nod*2,st,piv,qst,qed,val)||query(nod*2+1,piv+1,ed,qst,qed,val)); 
		}
	}
}

void update(int nod,int st,int ed,int qst,int qed,int val){
	if(st>=ed){
		//printf("wall from %d to %d now hgt %d\n",st,ed,val);
		tree[nod]=max(tree[nod],val);
	} else if (qst<=st&&qed>=ed){
		//printf("wall from %d to %d now hgt %d\n",st,ed,val);
		tree[nod]=max(tree[nod],val);
		int piv=(st+ed)/2;
			update(nod*2,st,piv,qst,qed,val);
			update(nod*2+1,piv+1,ed,qst,qed,val);
	} else {
		int piv=(st+ed)/2;
		if (qed<=piv){
			update(nod*2,st,piv,qst,qed,val);
			tree[nod]=min(tree[nod*2],tree[nod*2+1]);
		} else if (qst>piv){
			update(nod*2+1,piv+1,ed,qst,qed,val);
			tree[nod]=min(tree[nod*2],tree[nod*2+1]);
		} else {
			update(nod*2,st,piv,qst,qed,val);
			update(nod*2+1,piv+1,ed,qst,qed,val);
			tree[nod]=min(tree[nod*2],tree[nod*2+1]);
		}
	}
}

int main(){
    scanf("%d",&t);
    FORU(it,1,t+1){
		ll ans=0;
		memset(tree,0,sizeof tree);
		pq<enemy> lis;
		scanf("%d",&n);
		int mn=INF,mx=-INF;
		FORU(i,0,n) { 
			scanf("%d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h);
			c+=MXN;
			d+=MXN;
			mn=min(mn,min(c,c+(b-1)*g));
			mx=max(mx,max(d,d+(b-1)*g));
			lis.push(enemy(a,b,c,d,e,f,g,h));
		}
		while(!lis.empty()){
			vector<enemy> today;
			today.pb(lis.top());
			lis.pop();
			while (!lis.empty()&&lis.top().day==today.back().day){
				today.pb(lis.top());
				lis.pop();
			}
			//printf("day %d:\n",today.back().day);
			FORU(i,0,today.size()){
				enemy now=today[i];
				//printf("%d %d %d",now.st,now.ed,now.hgt);
				if(query(1,mn,mx,now.st,now.ed-1,now.hgt)) {
					//printf(" SUCCESS\n");
					++ans;
				} //else printf(" FAIL\n");
				if(now.atk>1) lis.push(enemy(now.day+now.dday,now.atk-1,now.st+now.dmov,now.ed+now.dmov,now.hgt+now.dhgt,now.dday,now.dmov,now.dhgt));
			}
			FORU(i,0,today.size()){
				enemy now=today[i];
				update(1,mn,mx,now.st,now.ed-1,now.hgt);
			}
		}
		printf("Case #%d: ",it);
		printf("%d\n",ans);
	}
	return(0);
}
