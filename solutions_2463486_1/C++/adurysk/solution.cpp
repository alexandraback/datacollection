#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

#define LL long long
#define LD long double

#define VI vector<int>

#define sd(x) scanf("%d",&x)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define PI pair< int , int >
#define PP pair< PI , PI >
#define MAXN 10000001
#define get getchar

char ch;
LD ret;

inline LD nexT(){
    ch=get();
    while(ch<'0'||ch>'9'){
        ch=get();
    }
    ret=0;
    while(ch>='0'&&ch<='9'){
        ret*=10;
        ret+=ch-48;
        ch=get();
    }
    return ret;
}

int d[MAXN]={0};

void preprocess(){
    LL i,j,k,l,r,m,n,w[16];
    d[0]=0;
    for(i=1;i<MAXN;i++){
        n=i;
        k=0;
        while(n){
            w[k++]=n%10;
            n/=10;
        }
        for(j=0;j<k;j++){
            if(w[j]!=w[k-j-1])
                break;
        }
        if(j==k){
            n=i*i;
            k=0;
            while(n){
                w[k++]=n%10;
                n/=10;
            }
            for(j=0;j<k;j++){
                if(w[j]!=w[k-j-1])
                    break;
            }
            if(j==k){
                d[i]=1;
            }
        }
        d[i]+=d[i-1];
    }
}

LD a,b;
LL p,q;

inline void solve(int c){
    a=nexT();
    b=nexT();
    p=sqrt(a);
    q=sqrt(b);
    if(p*p==a){
        p--;
    }
    printf("Case #%d: %d\n",c,d[q]-d[p]);
}

int main(){
    preprocess();
    int t,c=1;
    freopen("C-large-1.in","r",stdin);
    freopen("Csmallout.txt","w",stdout);
    /*
    for(t=1;t<10000001;t++){
        if(d[t]-d[t-1]==1){
            cout<<t<<endl;
        }
    }
    */
    cin>>t;
    while(t--){
        solve(c);
        c++;
    }
    return 0;
}
