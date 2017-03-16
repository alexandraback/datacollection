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
    
    int a,b,c;
    cin>>a>>b>>c;
    
    
    int ans = 0;
    for(int i=0;i<a;++i)
    for(int j=0;j<b;++j) if((i&j)<c) ++ans;
    
    cout<<"Case #"<<test<<": ";
    
    cout<<ans;
    
    cout<<endl;
}

int main(){
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    
    int tn;
    cin>>tn;
    for(int ti=1;ti<=tn;++ti){
        cerr<<ti<<"..."<<endl;
        solve(ti);
        cerr<<ti<<" ok."<<endl;
    }
    
    
    return 0;
}

