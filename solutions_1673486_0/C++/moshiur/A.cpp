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

int A,B;
double pr[100000+5];
double dp[100000+5];

double solve(){
    double gotRight = 1.0;

    double ret = 0.0;

    FOR(i,A){
        double tmp=gotRight*double(A-i+B-i+1) + (1.-gotRight)*double(A-i+B-i+1+B+1);

        if(i==0)
            ret = tmp;
        else
            ret = min(ret, tmp);
        gotRight *= pr[i];
    }

    // all correct
    double tmp = gotRight*double(B-A+1) + (1.-gotRight)*double(B-A+1+B+1);
    ret = min(ret, tmp);

    ret = min(ret, double(B+2));

    return ret;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
   freopen("A_small.out","w",stdout);

    int T;

    scanf("%d",&T);

    REP(t,1,T){
        scanf("%d%d",&A,&B);
        FOR(i,A)scanf("%lf",&pr[i]);

        printf("Case #%d: %.6lf\n",t,solve());
    }

    return 0;
}
