#include    <bits/stdc++.h>

#define     M_PI            3.14159265358979323846
#define     mod             1000000007
#define     inf             1000000000000000000
#define     mp              make_pair
#define     pb              push_back
#define     F               first
#define     S               second
#define     ll              long long
#define     pii             pair<int,int>
#define     pli             pair<ll,int>
#define     pil             pair<int,ll>
#define     pll             pair<ll,ll>
#define     si(t)           scanf("%d",&t)
#define     sii(m,n)        scanf("%d %d",&m,&n);
#define     sl(t)           scanf("%lld",&t)
#define     rep(i,n)        for(int i=0;i<n;i++)
#define     REP(i,a,b)      for(int i=a;i<=b;i++)
#define     RREP(i,a,b)     for(int i=a;i>=b;i--)
#define     N               5005

using namespace std;

int n,ans; 
pair<string,string> arr[20];

void fun(int a){
	map<string,int> ff,lst;
	int c=0;
	rep(i,n){
		if((1<<i)&a){
			c++;
			ff[arr[i].F]++;
			lst[arr[i].S]++;
		}
	}
	rep(i,n){
		if(!((1<<i) & a)){
			if(ff[arr[i].F] == 0 || lst[arr[i].S] == 0) return ; 
		}
	}
	ans = max(ans,n-c);
}

int main(){
    int t; si(t);
    REP(T,1,t){
    	ans = 0;
    	si(n);
    	rep(i,n){
    		cin>>arr[i].F>>arr[i].S;
    	}
    	int k = 1<<n;
    	rep(i,k){
    		fun(i);
    	}
    	printf("Case #%d: %d\n",T,ans );
    }
    return 0;   
}