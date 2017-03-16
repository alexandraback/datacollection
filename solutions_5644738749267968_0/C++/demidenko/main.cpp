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

const int N = 11;

double a[N], b[N];
int n;
int d[1<<N][1<<N];

int g(int m1, int m2){
    int &res = d[m1][m2];
    if(res==-1){
        res = 0;
        int j;
        for(int i=0;i<n;++i) if(m2>>i&1){
            j = i;
            break;
        }
        for(int i=0;i<n;++i) if(m1>>i&1){
            if(a[i]>b[j]) res = max(res, g(m1^(1<<i), m2^(1<<j))+1);
        }
        
        for(int i=0;i<n;++i) if(m1>>i&1){
            int k = n;
            for(int j=0;j<n;++j) if(m2>>j&1){
                if(b[j]>a[i]) {k=j; break; }
            }
            for(int j=k;j<n;++j) if(m2>>j&1){
                res = max(res, g(m1^(1<<i), m2^(1<<j)));
            }
        }
    }
    return res;
}

void solve(int test){
    
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    
    sort(a,a+n);
    sort(b,b+n);
    memset(d,-1,sizeof d);
    d[0][0] = 0;
    
    int ans1=g((1<<n)-1, (1<<n)-1), ans2=0;
    
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

