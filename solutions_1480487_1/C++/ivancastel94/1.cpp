#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    long long int i,cases,t,n;
    double a[202],b,c[202],x,neg,numneg;
    cin>>t;
    cases=1;
    while(t>0){
        cin>>n;
        x=0;
        for(i=0;i<n;i++){
            cin>>c[i];
            x+=(double)c[i];
            }
        b=(x*2.0)/(double)n;
        neg=numneg=0;
        for(i=0;i<n;i++){
            a[i]=(b-c[i])*100/x;
            if(a[i]<0){
                neg+=a[i];
                numneg++;
                }
            }
        if(numneg>0){
            for(i=0;i<n;i++){
                if(a[i]<0)a[i]=0;
                else a[i]=a[i]+neg/(double)(n-numneg);
                }
            }
        cout<<"Case #"<<cases<<":";
        for(i=0;i<n;i++)printf(" %lf",a[i]);
        cout<<endl;
        cases++;
        t--;
        }
    }
