#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int T,i,j,k,tt=0;
    long long r,t,ans,L,R;
    freopen("A.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>r>>t;
        L=1;R=10000000000LL;
        while(L<=R){
            long long mid=(L+R)/2;
            long long S=r+1+r+(mid-1)*2;
            if(S<=t/mid)L=mid+1;
            else R=mid-1;
        }
        tt++;
        cout<<"Case #"<<tt<<": "<<R<<endl;
    }
    return 0;
}

