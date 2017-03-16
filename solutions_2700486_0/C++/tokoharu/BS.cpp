#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
using namespace std;


typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define REP(i,n) for(int i=0;i<(int)n;i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(c) (c).begin(),(c).end()


int N,X,Y;
int bunbo = 0;
int cnt = 0;
void dfs(int a,int b,int c,int d,int e,int f,int g) {
    if(a+b+c+d+e+f+g==N) {
        bunbo++;
//        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        if(X+Y==0) cnt++;
        if(X+Y==2) {
            if(X==0 && a==2) cnt++;
            if(X!=0 && Y<b) cnt++;
        }
        if(X+Y==4) {
            if(X==0 && a==3) cnt++;
            if(X!=0 &&Y<d) cnt++;
        }
        if(X+Y==6) {
            if(Y<f) cnt++;
            
        }
        return;
    }
    
    if(a==0) {
        a++, dfs(a,b,c,d,e,f,g);
        return ;
    }
    if(b==2 && c==2 && a==1) {
        a++;
        dfs(a,b,c,d,e,f,g);
        return ;
    }
    if(!(b==2 && c==2)) {
        if(b<2)dfs(a,b+1,c,d,e,f,g);
        if(c<2)dfs(a,b,c+1,d,e,f,g);
        return ;
    }
    if(d==4 && e==4 && a==2) {
        dfs(a+1,b,c,d,e,f,g);
        return ;
    }
    if(!(d==4 && e==4)) {
        if(d<4)dfs(a,b,c,d+1,e,f,g);
        if(e<4)dfs(a,b,c,d,e+1,f,g);
        return ;
    }
    if(f<6)dfs(a,b,c,d,e,f+1,g);
    if(g<6)dfs(a,b,c,d,e,f,g+1);
}


double solve() {
    bunbo = cnt = 0;
    cin>>N>>X>>Y;
    X = abs(X);
    dfs(0,0,0,0,0,0,0);
    
    return (double)cnt/bunbo;
    
}
int main() {
    /*
     REP(i,10) {
     REP(j,10) cout<<sumT[i][j]<<" ";
     cout<<endl;
     }
     */
    int t;
    cin>>t;
    for(int i=1; i<=t; i++) {
        double ans = solve();
        cout<<"Case #"<<i<<": ";
        printf("%.10lf",ans);
        cout<<endl;
    }
    return 0;
}

