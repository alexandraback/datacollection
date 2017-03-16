#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#define PI 1
#include <queue>
#define FOR(i,a)    for(int i = 0;i<(a);i++)
#define REP(i,a,b)  for(int i = (a);i<(b);i++)
#define SZ(a)   ((signed)a.size())

using namespace std;

int caseno = 1;

void solve(){
    long long r,v;
    cin>>r>>v;
    long long b = 1,e = ((long double)sqrt((long double)v)) + 1;
    long long ans;
    while(b <= v){
        long long mid = (b + e)/2;
        long double vv = 2 * r  + (2 * mid - 1);
        if(vv == v/(long double)mid){
            ans = mid;break;
        }
        else if(vv > v/(long double)mid){
            e = mid - 1;
        }
        else {
            long double vvv = 2 * r + (2 * mid + 1);
            if(vvv > v/((long double)mid + 1)){
                ans = mid;break;
            }
            b = mid + 1;
        }
    }
    cout<<"Case #"<<caseno<<": "<<ans<<"\n";
    caseno++;
}

int main(){
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    int t;
    cin>>t;
    FOR(i,t)    solve();
    return 0;
}
