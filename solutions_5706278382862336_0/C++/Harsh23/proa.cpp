#include<iostream>
#include<cstdio>
using namespace std;
bool check(long long &p,long long &q){
    long long temp=q;
    while(temp%2!=1){
        temp/=2;
    }
    q=q/temp;
    if(temp==1)
        return true;
    if(p%temp==0){
        p=p/temp;
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int t;
    long long p,q;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        cout<<"Case #"<<tt<<": ";
        scanf("%lld/%lld",&p,&q);
        bool flag=check(p,q);
        if(flag==true){
            int ans=0;
            while(q>2*p){
                if(q>2*p){
                    ans++;
                    q/=2;
                }
            }
            ans++;
            cout<<ans<<endl;
        }
        else{
            cout<<"impossible"<<endl;
        }
    }
}
