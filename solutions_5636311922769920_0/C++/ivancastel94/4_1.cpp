#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("4.in","r",stdin);
    freopen("4.out","w",stdout);
    int i,t,cases,k,c,s;
    cin>>t;
    cases=1;
    while(cases<=t){
        cin>>k>>c>>s;
        cout<<"Case #"<<cases<<":";
        if(k==s){
            for(i=1;i<=k;i++)cout<<" "<<i;
            cout<<endl;
        }
        else{
            cout<<" IMPOSSIBLE"<<endl;
        }
        cases++;
    }
}
