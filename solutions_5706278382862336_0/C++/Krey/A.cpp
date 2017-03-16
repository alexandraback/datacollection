#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
long long k,p,q,t,wyn;
char c;
int main(){
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d%c%d",&p,&c,&q);
        k=__gcd(p,q);
        p/=k;
        q/=k;
        k=q;
        while(k%2==0){
            k/=2;
        }
        if(k!=1) printf("Case #%d: impossible\n",tt);
        else{
            k=q;
            wyn=0;
            while(k>p){
                k/=2;
                wyn++;
            }
            printf("Case #%d: %d\n",tt,wyn);
        }
    }
}

