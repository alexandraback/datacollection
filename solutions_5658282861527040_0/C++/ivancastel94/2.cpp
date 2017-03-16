#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<set>
using namespace std;
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int res,i,j,l,a,b,k,t,cases;
    cin>>t;
    for(cases=1;cases<=t;cases++){
        cin>>a>>b>>k;
        cout<<"Case #"<<cases<<": ";
        if(a<=k||b<=k){
            res=a*b;
            cout<<res<<endl;
            continue;
        }
        res=k*a+k*b-k*k;
        for(i=k;i<a;i++){
            for(j=k;j<b;j++){
                l=i&j;
                if( l < k ) res++;
            }
        }
        cout<<res<<endl;
    }
}
