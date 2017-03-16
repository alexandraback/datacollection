#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=2000007;
int f[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    f[1]=1;
    for(int i=2; i<=1000000; ++i) f[i]=oo;
    for(int i=1; i<1000000; ++i){
        f[i+1]=min(f[i+1],f[i]+1);
        int x=i,y=0;
        while(x){
            y=y*10+(x%10);
            x/=10;
        }
        if(y<maxn && f[y] > f[i]+1) f[y]=f[i]+1;
    }

    int T,v;
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d",&v);
        printf("Case #%d: %d\n",tt,f[v]);
    }

}

