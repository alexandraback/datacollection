#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;
typedef long long int ll;

ll find_oper(ll *m, ll n, ll a,ll pos,ll flag){
    ll temp,x,y;
    if(pos==n)return 0;
    if(a>m[pos]){
        a=a+m[pos];
        pos++;
        return find_oper(m,n,a,pos,0);
    }
    else{
        if(flag==1)return 1+find_oper(m,n,a+a-1,pos,flag);
        x = 1+find_oper(m,n-1,a,pos,0);
        if(a==1)return x;
        
        y = 1+find_oper(m,n,a+a-1,pos,1);
        if(x<y)return x;
        else return y;
    }
}

int main() {

    int T;
    cin>>T;

    ll i,a,n,j,k,temp;
    ll m[1001];
    for(ll i=1;i<=T;i++){
        cin>>a;
        cin>>n;
        for(j=0;j<n;j++)cin>>m[j];
        for(j=0;j<n-1;j++){
            for(k=j+1;k<n;k++){
                if(m[j]>m[k]){
                    temp=m[j];
                    m[j]=m[k];
                    m[k]=temp;
                }
            }
        }
        printf("Case #%lld: %lld\n",i,find_oper(m,n,a,0,0));
    }

    return 0;
}
