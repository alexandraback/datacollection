#include<bits/stdc++.h>
#define MAX   1010
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int INF=(int)1e9+7;
int minCost[MAX][MAX];
int a[MAX],n;
void precount(void) {
    FOR(i,1,MAX-1) FOR(j,1,i-1) {
        minCost[i][j]=INF;
        FOR(k,1,i-1) minCost[i][j]=min(minCost[i][j],minCost[k][j]+minCost[i-k][j]+1);
    }
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void process(int tc) {
    int maxVal=a[1];
    FOR(i,1,n) maxVal=max(maxVal,a[i]);
    int res=maxVal;
    FOR(i,1,maxVal) {
        int s=0;
        FOR(j,1,n) s+=minCost[a[j]][i];
        res=min(res,s+i);
    }
    printf("Case #%d: %d\n",tc,res);
}
int main(void) {
    precount();
    int t;
    scanf("%d",&t);
    FOR(i,1,t) {
        init();
        process(i);
    }
    return 0;
}
