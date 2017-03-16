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

int n,powTen[8];

int power(int a,int b){
	return powTen[b];
}

int chk(int a,string s){
	rep(i,n){
		if(s[i] != '?'){
			int p = (a/power(10,n-i-1))%10;
			if(p != s[i]-'0') return 0;
		}
	}
	return 1;
}


int main(){
	powTen[0] = 1;
	REP(i,1,7) powTen[i] = powTen[i-1]*10;
    int t; si(t);
    REP(T,1,t){
    	string a,b;
        int aa,bb,mn=mod;
        cin>>a>>b;
        n = a.length();
        int k = power(10,n);
        rep(i,k){
        	int p = chk(i,a);
        	if(p){
        		rep(j,k){
        			int pp = chk(j,b);
        			if(pp){
        				if(abs(i-j) < mn){
        					aa = i;
        					bb = j;
        					mn = abs(i-j);
        				}
        			}
        		}
        	}
        }
        rep(i,n){
        	a[n-i-1] = aa%10+'0';
        	b[n-i-1] = bb%10+'0';
        	bb /= 10;
        	aa /= 10;
        }
        printf("Case #%d: ",T );
        cout << a << " " << b ;
        printf("\n");
    }
    return 0;   
}