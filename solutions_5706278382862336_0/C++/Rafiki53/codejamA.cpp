#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<list>
#include<math.h>
#include<algorithm>
#include<string>
#include<set>
#include<queue>
#define limit 1048576
#define inf 9223372036854775807ll
#define iinf 2147483647
#define mp make_pair
#define pb push_back
#define rep(i,k,n) for(int i=k;i<n;i++)
using namespace std;
long long euc(long long a, long long b){
    if(b==0) return a;
    else return euc(b,a%b);
}
int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w",stdout);
    long long a,b,t,k,ans,nwd;
    char c;
    cin >> t;
    rep(i,1,t+1){
        a=0;
        b=0;
        c=getchar();
        if(c=='\n') c=getchar();
        while(c!='/'){
            a*=10;
            a+=c-'0';
            c=getchar();
        }
        c=getchar();
        while(c!='\n'){
            b*=10;
            b+=c-'0';
            c=getchar();
        }
        nwd=euc(max(a,b),min(a,b));
        a/=nwd;
        b/=nwd;
        k=0;
        ans=0;
        while(b%2==0){
            if(a>1){
                a/=2;
                ans++;
            }
            k++;
            b/=2;
        }
        if(k>40 || b!=1) cout << "Case #" << i <<": impossible\n";
        else cout << "Case #" << i << ": " << k-ans <<"\n";
    }
    return 0;
}
