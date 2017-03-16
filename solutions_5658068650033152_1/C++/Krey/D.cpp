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

int t,n,m,k,wyn,l,p,o;

int main(){
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d%d%d",&n,&m,&k);
        int wyn = k;
        for(int i=3;i<=n;i++){
            for(int j=3;j<=m;j++){
            l = i*j-4;
            p = (i-2)*2 + (j-2)*2;
            o = max(0,k-l);
            wyn = min(wyn,p+o);
            if(l-k >= 2) wyn = min(wyn,p+o-1);
            }
        }
        printf("Case #%d: %d\n",tt,wyn);
    }

}

