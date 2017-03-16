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

int A, N, M[500];

int calc(int newMote){
    int at = 0;
    int cur = A;

    while(newMote > 0 && at < N){
        if(M[at] < cur){
            cur += M[at]; at++;
        }
        else{
            cur += cur-1; --newMote;
        }
    }

    while (at < N){
        if(M[at] < cur){
            cur += M[at]; ++at;
        }
        else
            break;
    }

    return N - at;
}

int main(){
    freopen("A_small.in","r",stdin);
    freopen("A_small_output.out","w",stdout);


    int T=INT;

    REP(t,1,T){
        A=INT; N=INT; FOR(i,N)M[i]=INT;
        sort(M, M+N);

        int ans = N;

        for(int newMote = 0; newMote <= N; ++newMote){
            ans = min(ans, newMote + calc(newMote));
        }

        printf("Case #%d: %d\n",t,ans);
    }

    return 0;
}
