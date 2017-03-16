#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
#define EPS 1e-7
int n,jv;
int inp[207];
double op[207];
void slv(int x){
    double lo=0; double hi=100;
    double mine,her,mid;
    while( fabs(hi-lo)> EPS){
        mid= hi+lo;
        mid= mid/2;
        mine= mid*jv*0.01+inp[x];

        double td=0;
        for(int i=0;i<n;i++){
            if(i==x) continue;
            double cd= mine-inp[i];
            if(cd<=0) continue;
            cd= cd/jv;
            td+= cd;
        }
        if( (td+mid*0.01)>=1) hi=mid;
        else lo=mid;
        //cout<<mid<<" ";
    }
    op[x]=mid;

}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
int gt;
cin>>gt;
for(int run=1;run<=gt;run++){
    cin>>n;
    jv=0;
    for(int i=0;i<n;i++) cin>>inp[i],jv+=inp[i];

    for(int i=0;i<n;i++) slv(i);

    //slv(0);

    printf("Case #%d:",run);
    for(int i=0;i<n;i++) printf(" %0.8lf",op[i]);
    printf("\n");

}
    return 0;
}
