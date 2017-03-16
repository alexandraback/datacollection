#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"
#include "iostream"
#include "algorithm"
#include "set"
#include "vector"
#include "queue"
#include "map"
#include "list"
#include "string"
using namespace std;
#define ll long long
#define rp(i,n) for(ll i=1;i<=n;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define clr(a,b) memset(a,b,sizeof(a))
#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define sc(x) scanf("%c",&x)
#define line puts("");
#define IN freopen("i.txt","r",stdin);
#define OUT freopen("o.txt","w",stdout);
#define N 1000000
//lower_bound binary_search push_back insert

ll a,b,n,m,k,T,ans,len,C;
char str[50];
int main(){
	// IN 
	// OUT
	sll(T);C=1;
	while(T--){
		printf("Case #%lld: ",C++);
		ll p,q;
		ss(str);
		string s(str);
		a=s.find("/");
		p=stoll(s.substr(0,a));
		q=stoll(s.substr(a+1));
		ll gcd;
		a=q,b=p;
		while((a%=b)&&(b%=a));
		gcd=a+b;
		p/=gcd,q/=gcd;
		bool flag=(q&(q-1))==0;
		if(flag){
			ans=0;
			while(p<q){p<<=1;ans++;}
			printf("%lld\n", ans);
		}
		else{
			printf("impossible\n");
		}
	}
	return 0;
}














