#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
 
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second


#define DEBUG 0
#define max_n 205
int n;
int sum;
int t[500];
double res[500];
double wyn[500];

bool czy(int k, double x){
    
    double reszta = 1.0-x;
    FOR(i,0,n){
        if(i!=k){
            if(wyn[i]<wyn[k]+x){
                reszta-=(wyn[k]+x-wyn[i]);
            }
        }
    }
    if(reszta<0.) return true;
    else return false;
}

void rob(int k){
    double l=0.0,r=1.0;
    while(r-l>0.00000001){
        if( czy(k,(r+l)/2) ) 
            r = (r+l)/2;
        else l = (r+l)/2;
    }
    res[k] = (r+l)/2;
}





int main(){
    int z; scanf("%d",&z);
    FOR(Z,1,z+1){
        scanf("%d",&n);
        FOR(i,0,n) scanf("%d",&t[i]);
        sum = 0; FOR(i,0,n) sum+=t[i];

        FOR(i,0,n) wyn[i] = t[i]*1.0/sum;

        printf("Case #%d:",Z);
        FOR(i,0,n) rob(i);
        FOR(i,0,n) printf(" %lf",res[i]*100.0);
        printf("\n");
    }
    return 0;
}
