#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>

#define For(i,n) for(long long i = 0;i<n;i++)
#define Fors(var,start,finish) for(long long var = start, var <=finish, var++)

using namespace std;

const long long maxn = 10010;
long long n,m,ntest;
long long a[maxn],b[maxn];
long long typea[maxn];
long long typeb[maxn];
long long res;
long long lb[maxn];
long long la[maxn];

void init(){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(typea,0,sizeof(typea));
    memset(typeb,0,sizeof(typeb));
    res = 0;
}

void check(long long i,long long j,long long t){
    long long r = 0;
    for(long long u = 0;u<=i;u++){
        if (a[0] <= 0) continue;
        if (b[u]<=0) continue;
        if (typeb[u] == typea[0]){
            long long addval = min(a[0],b[u]);
            r += addval;
            a[0] -= addval;
            b[u] -= addval;
        }
    }
    if (n>1){
        for(long long u = i;u<=j;u++){
            if (a[1]<=0) continue;
            if (b[u]<=0) continue;
            if (typeb[u] == typea[1]){
                long long addval = min(a[1],b[u]);
                r += addval;
                a[1] -= addval;
                b[u] -= addval;
            }
        }
    }
    
    if (n>2){
        for(long long u = j;u<=t;u++){
            if (a[2]<=0) continue;
            if (b[u]<=0) continue;
            if (typeb[u] == typea[2]){
                long long addval = min(a[2],b[u]);
                r += addval;
                a[2] -= addval;
                b[u] -= addval;
            }
        }
    }
    res = max(res,r);
}

void solve(){
    For(i,m){
        for(long long j = i;j<m;j++){
            for(long long t = j;t<m;t++){
                For(k,m){
                    lb[k] = b[k];
                    la[k] = a[k];
                }
                check(i,j,t);      
                For(k,m){
                    b[k] = lb[k];
                    a[k] = la[k];
                }
               // cout<<i<<j<<t<<endl;      
            }
        }
    }
    cout<<res;
}

void input(){
    cin>>n>>m;
    For(i,n){
        cin>>a[i]>>typea[i];
    }
    For(i,m){
        cin>>b[i]>>typeb[i];
    }
}


int main(){
   // freopen("C.in","r",stdin);
    cin>>ntest;
    For(i,ntest){
        init();
        input();
        cout<<"Case #"<<i+1<<": ";
        solve();
        cout<<endl;
    }
    return 0;
}
