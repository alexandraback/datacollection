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

int score[500];
int n;
double sum;
const double eps = 0.000000001;

bool possible(double x){
    double need = 0.0;
    FOR(i,n){
        if((double)score[i] < x)
            need += (x-(double)score[i]);
    }

    return (need < sum+eps);
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A_large.out","w",stdout);

    int T; scanf("%d",&T);

    REP(t,1,T){
        scanf("%d",&n);
        FOR(i,n)scanf("%d",&score[i]);

        sum = 0;
        FOR(i,n)sum+=(double)score[i];

        double lo = 0.0, hi = sum+1.0;

        FOR(i,100){
            double mid = (lo+hi)/2.0;

            if(possible(mid))
                lo = mid;
            else
                hi = mid;
        }

        printf("Case #%d:",t);

        FOR(i,n){
            if((double)score[i]+eps > lo)
                printf(" %lf",0.0);
            else
                printf(" %lf",((lo-score[i])/sum)*100.0);
        }

        puts("");
    }

    return 0;
}
