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

const int N = 1111;

double a[N], b[N];
int n;

void solve(int test){
    
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    
    sort(a,a+n);
    sort(b,b+n);
    
    int ans1 = 0, ans2=0;
    
    //ans1=g((1<<n)-1, (1<<n)-1)
    
    int j = 0;
    for(int i=0;i<n;++i){
        j = upper_bound(a+j,a+n,b[i]) - a;
        if(j==n) break;
        ++ans1;
        ++j;
    }
    
    do{
        int x=0,y=0;
        set<double> q(b,b+n);
        for(int i=0;i<n;++i){
            set<double>::iterator it = q.upper_bound(a[i]);
            if(it==q.end()){
                ++x; 
                q.erase(q.begin());
            }else{
                ++y;
                q.erase(it);
            }
            if(n-i-1+x<=ans2) break;
        }
        ans2 = max(ans2, x);
        break;
    }while(next_permutation(a,a+n));
    
    cout<<"Case #"<<test<<": ";
    
    cout<<ans1<<' '<<ans2;
    
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

