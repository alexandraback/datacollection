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
long long r,t;

const double PI = std::atan(1.0)*4;

long long vl(long long x){

    long long cur= x;

    if( t/x < r ) return t+1;
    if( t/x < x ) return t+1;

    cur =  cur + 2*( x*r + x*(x-1));
    return cur;
}

long long bs(long long lo,long long hi){
    if(hi-lo<=1){
        if(vl(hi)<=t) return hi;
        return lo;
    }
    long long mid= lo+ (hi-lo)/2;
    if(vl(mid)>t) return bs(lo,mid);
    return bs(mid,hi);
}

int main(){
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);

    int gt,run;
    cin>>gt;
    long long ret;
    for(int run=1;run<=gt;run++){
        cin>>r>>t;

        ret= bs(0,t);

        cout<<"Case #"<<run<<": "<<ret<<endl;

    }
    return 0;
}




