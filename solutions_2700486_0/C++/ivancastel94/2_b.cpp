#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;

long long comb[100][100];

long long com(int n, int k){
    if(comb[n][k]!=0)return comb[n][k];
    if(n<k||n==0)
        return 0;
    if(n==k||k==0)
        return 1;
    return comb[n][k]=com(n-1,k-1)+com(n-1,k);
    }

long double prob(int n, int k, int h){
    double s=com(n,k)*pow(0.5,n);
    if(h+k<=n)return 1;
    return s;
    }

long double p(int n, int k, int h){
    int i;
    long double d=0;
    for(i=k;i<=n;i++){
        d=d+prob(n,i,h);
        }
    if(d>=1.0)d=1.0;
    return d;
    }

int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    long long i,n,x,y,t,cases,a[10003];
    cin>>t;
    a[0]=1;
    memset(comb,0,sizeof(int)*100*100);
    for(i=1;i<10003;i++){
        a[i]=a[i-1]+4;
        }
    for(i=1;i<10003;i++){
        a[i]=a[i-1]+a[i];
        }
    for(cases=1;cases<=t;cases++){
        cin>>n>>x>>y;
        i=0;
        while(a[i]<=n&&i<10003){
            i++;
            }
        if(abs(x)+abs(y)<2*i){
            cout<<"Case #"<<cases<<": "<<1.0<<endl;
            continue;
            }
        if(abs(x)+abs(y)>2*i){
            cout<<"Case #"<<cases<<": "<<0.0<<endl;
            continue;
            }
        if(x==0){
            cout<<"Case #"<<cases<<": "<<0.0<<endl;
            continue;
            }
        cout<<"Case #"<<cases<<": "<<p(n-a[i-1],y+1,2*i)<<endl;
        }
    }
