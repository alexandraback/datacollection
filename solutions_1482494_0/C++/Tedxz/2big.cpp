#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
#define For(i,l,r) for(int i=l;i<=r;++i)
#define Cor(i,l,r) for(int i=l;i>=r;--i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define MaxN 1020
#define PII pair<int,int>
#define MP make_pair
#define FI first
#define SE second

PII a[MaxN];int b[2003];
int n;
void init(){
     scanf("%d",&n);
     For(i,1,n){
         scanf("%d%d",&a[i].FI,&a[i].SE);
     }
}

bool Del[MaxN],One[MaxN];
void Sol(){
    init();
    Fill(Del,0);Fill(One,0);
    int now(0),rem(n);int ans = 0;
    while(rem){
        int tMin = 2010,tPos = 0;
        For(i,1,n)if(!Del[i]){
            tMin = min(tMin,a[i].SE);
            if(tMin == a[i].SE) tPos = i;
        }
        if(tMin <= now){
            Del[tPos] = true;
            --rem;++ans;now += 2;now -= One[tPos];
            continue;
        }
        int tMax = -1;tPos = 0;
        For(i,1,n){
            if((!Del[i])&&(!One[i])&&(a[i].FI<=now)){
                if(a[i].SE >= tMax){
                     tMax = a[i].SE;tPos = i;
                }
            }
        }
        if(tMax >= 0){
            One[tPos] = true;++ans;
            now++;
            continue;
        }
        printf("Too Bad\n");
        return;
    }
    cout<<ans<<endl;
}

int cas;
int main(){
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    scanf("%d",&cas);int cnt = 0;
    while(cas--){
        printf("Case #%d: ",++cnt);
        Sol();
    }
}
