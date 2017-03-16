#include<iostream>
#include<cstdio>
using namespace std;
int gen(long long p, long long q){
    while(q%2==0)q=q/2;
    if(p%q==0)return 1;

    return -1;
}
int ancestor(double val){
    int a=0;
    while(val<1){
        val*=2;
        a++;
    }
    return a;
}
int main(){
    long long t,p,q;
    double val;
    cin>>t;
    for(int i=1;i<=t;i++){
        scanf("%lld/%lld",&p,&q);
        val=(double)p/(double)q;

        if(gen(p,q)==-1){
            printf("Case #%d: impossible\n",i);
        }
        else
            printf("Case #%d: %d\n",i,ancestor(val));
    }
    return 0;
}
