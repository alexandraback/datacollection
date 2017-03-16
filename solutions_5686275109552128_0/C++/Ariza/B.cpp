#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define EPS (1e-10)
#define lef(x) (x<<1)
#define rig(x) (x<<1)+1
#define PI (2*acos(0.0))

int rec(vector<int> vec){
    //for (int i=0;i<vec.size();++i) cout << vec[i] << " ";
    //cout << endl;
    if (vec[vec.size()-1]<=3) return vec[vec.size()-1];
    vector<int>v1,v2;
    int ctr=vec[vec.size()-1]/2;
    v1.pb(ctr); v1.pb(vec[0]-ctr);
    for (int i=0;i<vec.size()-1;++i) if (vec[i]>0) v1.pb(vec[i]);
    sort(v1.begin(),v1.end());
    
    for (int i=0;i<vec.size();++i){
        if (vec[i]-1>0) v2.pb(vec[i]-1);
    }
    return 1+min(rec(v1),rec(v2));
}

void solve(){
     printf(" ");
     /*
     int d,p;
     priority_queue<int> Q;
     scanf("%d",&d);
     for (int i=0;i<d;++i){
         scanf("%d",&p);
         Q.push(p);
     }
     
     int ans = 1000000000;
     int tmp,eaten=0;
     for (int i=0;;++i){
         p = Q.top();
         Q.pop();
         
         ans = min(ans, p+i);
         
         if (p==1) break;
         tmp = (p>>1);
         Q.push(tmp); Q.push(p-tmp);
     }
     printf("%d\n",ans);
     */
     int d,p;
     vector<int> v;
     scanf("%d",&d);
     for (int i=0;i<d;++i){
         scanf("%d",&p);
         v.pb(p);
     }
     sort(v.begin(),v.end());
     printf("%d\n",rec(v));
}
int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d:",test);
        solve();
    }
    return 0;
}
