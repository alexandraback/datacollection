#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
using namespace std;
typedef long long ll;

const int N = 1e6+6;

void solve(int test){
    
    double C,F,X;
    cin>>C>>F>>X;
    
    double r = 2.0;
    double s = 0.0;
    
    
    double ans = 1e18;
    for(;;){
        double t1 = X/r;
        double t2 = C/r;
        
        if(ans>s+t1) ans = s+t1; else break;
        
        s+=t2;
        r+=F;
    }
    
    
    cout<<"Case #"<<test<<": ";
    
    cout<<fixed<<ans;
    
    cout<<endl;
}

int main(){
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    
    int tn;
    cin>>tn;
    cout.precision(12);
    for(int ti=1;ti<=tn;++ti){
        cerr<<ti<<"..."<<endl;
        solve(ti);
        cerr<<ti<<" ok."<<endl;
    }
    
    
    return 0;
}

