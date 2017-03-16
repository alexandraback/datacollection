#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int a[300],n,T,h;
double c[300];

bool check(int x,double w){
    double r=a[x]+w*h;
    for(int i=0;i<x; ++i) c[i]=a[i];
    for(int i=x+1;i<n; ++i) c[i-1]=a[i];

    sort(c,c+n-1);
    double rm=(1-w)*h;
    if(r-c[0]<-1e-9) return false;
    for(int i=0;i<n-1;++i){
        int j=i;
        for(;j<n-1 && c[j]-c[i]<1e-9;++j);
        double t=rm;
        if(j<n-1 && (c[j]-c[j-1])*j<rm+1e-9) t=(c[j]-c[j-1])*j;
        for(int k=0;k<j;++k) c[k] += t/j;
        if(r-c[0]<-1e-9) return false;
        rm-=t;
        if(rm<1e-9) break;
    }
    return true;
}
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    for(int cs=1;cs<=T; ++cs){
        scanf("%d",&n);
        h=0;
        for(int i=0;i<n;++i) {
             scanf("%d",&a[i]);
             h+=a[i];
        }

        printf("Case #%d:",cs);
        for(int i=0;i<n;++i){
            double l=0, r=1;
            while(l+1e-8<r){
                double m=(l+r)/2;
                if(check(i,m)) r=m; else l=m;
            }
            printf(" %.6f",l*100);
        }
        puts("");
    }
    return 0;
}
