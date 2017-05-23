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
#define MXN 100000000000000LL
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

int n; 
vector<ll> anslis;

bool palindrome (vi a){
	FORU(i,0,a.size()/2) if (a[i]!=a[a.size()-i-1]) return false;
	return true;	
}

vi bignumsqr(vi a){
	int l=a.size();
	vi tmp(2*l,0);
	FORU(i,0,l) FORU(j,0,l){
		int x=a[i]*a[j];
		tmp[i+j]+=x;
	}	
	FORU(i,0,tmp.size()) if (tmp[i]>9){
		tmp[i+1]+=tmp[i]/10;
		tmp[i]%=10;	
	}
	while(tmp.back()==0) tmp.pop_back();
	return tmp;
}

bool bignumless(vi a,vi b){
	FORD(i,a.size(),0);	
}

void check(vi tmp){
	if (tmp.size()>10) return;
	//FORU(i,0,tmp.size()) printf("%d",tmp[i]); printf("\n");
	vi sqred=bignumsqr(tmp);
	//DEBUG(" AAA");
	//FORU(i,0,sqred.size()) printf("%d",sqred[i]); printf("\n");
	if (palindrome(sqred)) {
		ll tmp=0;
		FORD(i,sqred.size(),0){
			tmp=tmp*10+sqred[i];
		}
		anslis.pb(tmp);
	}
}

void createpal(vi lis){
	if (lis.size()>0){
		vi rev=lis;	FORD(i,lis.size(),0) rev.pb(lis[i]);
		check(rev);
		rev=lis; rev.pb(0); FORD(i,lis.size(),0) rev.pb(lis[i]); 
		check(rev);
		rev[lis.size()]=1;
		check(rev);
		rev[lis.size()]=2;
		check(rev);
	} else {
		vi tmp;
		tmp.pb(1);
		check(tmp);
		tmp[0]=2;
		check(tmp);
		tmp[0]=3;
		check(tmp);	
	}
}

void permute(vi lis, int siz){
	if (siz==4){
		reverse(lis.begin(),lis.end());
		while (lis.size()>0&&lis.back()==0) lis.pop_back();
		reverse(lis.begin(),lis.end());
		//FORU(i,0,lis.size()) printf("%d ",lis[i]); printf("\n");
		createpal(lis);	
	} else {
		lis.pb(0);
		permute(lis,siz+1);
		lis[siz]=1;
		permute(lis,siz+1);
		lis[siz]=2;
		permute(lis,siz+1);	
	}
}

int main(){
	vi lol;
	permute(lol,0);
	//FORU(i,0,ans.size()) printf("%lld\n",ans[i]);
	scanf("%d",&n);
	//printf("ANSLIS --- %d\n",anslis.size());
	sort(anslis.begin(),anslis.end());
	//FORU(i,0,anslis.size()){
	//	printf("%lld\n",anslis[i]);	
	//}
    FORU(i,0,n){
		ll bna,bnb;
		scanf("%lld %lld",&bna,&bnb);	 
		std::vector<ll>::iterator stt=std::lower_bound(anslis.begin(),anslis.end(),bna),
								  edd=std::upper_bound(anslis.begin(),anslis.end(),bnb);
		printf("Case #%d: %d\n",i+1,edd-stt);
	}
	return(0);
}
