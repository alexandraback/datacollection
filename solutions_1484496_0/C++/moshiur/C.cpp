#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
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

#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLR(a,x) memset(a,(x),sizeof(a))

int GET_INT(){int ret; scanf("%d",&ret); return ret;}

#define INT GET_INT()

typedef long long LL;
typedef pair<int,int> pii;

int prev[100000*20 + 10];

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C_small.out","w",stdout);

    int T; scanf("%d",&T);

    REP(t,1,T){
        int s[50];
        int n; scanf("%d",&n);
        FOR(i,n)scanf("%d",s+i);
        CLR(prev,0);

        printf("Case #%d:\n",t);

        bool found=0;

        for(int mask=1;mask<(1<<n);++mask){
            int sum=0;
            FOR(i,n){
                if((mask>>i)&1){
                    sum+=s[i];
                }
            }
            if(prev[sum]!=0){
                found=true;
                int cnt=0;
                int tmp=prev[sum];
                FOR(j,n)if(tmp&(1<<j)){
                    ++cnt;
                    if(cnt>1)printf(" ");
                    printf("%d",s[j]);
                }
                puts("");
                cnt=0;
                FOR(j,n)if(mask&(1<<j)){
                    ++cnt;
                    if(cnt>1)printf(" ");
                    printf("%d",s[j]);
                }
                puts("");

                break;
            }
            prev[sum] = mask;
        }


        if(!found)puts("Impossible");
    }

    return 0;
}
