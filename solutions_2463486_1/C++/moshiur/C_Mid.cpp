#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//#define DEBUG_MODE

#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLR(a,x) memset(a,(x),sizeof(a))

#ifdef DEBUG_MODE
#define DBG(X) X
#else
#define DBG(X)
#endif

inline int ___INT(){int ret; scanf("%d",&ret); return ret;}
#define INT ___INT()

typedef long long LL;
typedef pair<int,int> pii;

bool isPal(LL x){
    LL _x=0;
    LL oldx=x;
    while(x){int d=x%10;x/=10; _x=_x*10LL+d;}
    return _x==oldx;
}

int pre[10000007];

int main(){

    freopen("C_mid.in","r",stdin);
    freopen("C_mid_output.txt","w",stdout);

    pre[0] = 1;

    for(LL i=1;i<=10000001;++i){
        int inc=0;
        if(isPal(i) && isPal(i*i)) inc=1;
        pre[i]=pre[i-1]+inc;
    }

    int T=INT;
    REP(t,1,T){
        LL A, B;
        cin>>A>>B;
        LL a = (int)sqrt(A);
        LL b = (int)sqrt(B);

        int ans=0;

        if(a==0) ans=pre[b];
        else{
            ans=pre[b];
            ans-=pre[a];
            if(a*a==A && pre[a]>pre[a-1]) ans++;
        }

        printf("Case #%d: %d\n",t,ans);
    }

    return 0;
}
