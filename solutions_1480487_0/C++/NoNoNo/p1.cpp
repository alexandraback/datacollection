#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<set>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second

const int MAXN=210;

double s[MAXN];
double suma;

int n;

double mm(double a, double b){
    return max(a-b,(double)0);
}

void readData(){
    scanf("%d",&n);
    suma=0;
    REP(i,n){
       scanf("%lf",&s[i]);
       suma+=s[i];
   }
}

double sum(double t){
    double w=0;

    REP(i,n){
        w+=mm(t,s[i]);
    }
    return w;
}

double licz(){
    double l=0,p=100000;
    while (p-l>0.000000001){
        if (suma>sum((l+p)/2)){
            l=(p+l)/2;
        }
        else {
            p=(p+l)/2;
        }
    }
    return l;
}

int t;

int main(){
    double wy;
    scanf("%d",&t);
    REP(i,t){
        readData();
        wy=licz();
            printf("Case #%d: ",i+1);
        REP(j,n){
            printf("%.6f ",100*mm(wy,s[j])/suma);
        }
        printf("\n");
    }
}
