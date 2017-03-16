#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef unsigned long long LL;
const int inf=1000000000;//1e9
LL bisearch(LL r,LL p){
    //cout<<r<<" "<<p<<endl;
    LL left=0;
    LL right=1000000000LL;
    LL ans=0;
    while (left<=right){
        LL mid=(left+right)/2;
        LL tmp=(2*r+2*mid+1);
        if (tmp<=p/(mid+1)) ans=max(ans,mid);
        if (tmp<=p/(mid+1)) left=mid+1;
        else right=mid-1;
    }
    return ans+1;
}
int main(){
    freopen("2.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        LL r,p;
        cin>>r>>p;
        LL tt=bisearch(r,p);
        cout<<"Case #"<<t<<": "<<tt<<endl;
    }
}
