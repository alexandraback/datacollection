#include<iostream>
#include<cstdio>
using namespace std;
int gen(double v){
    int x;
    for(int i=1;i<=40;i++){
        x=(int)v;
        if(x==v)return i;
        v*=2;
    }
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
    int t,p,q;
    double val;
    cin>>t;
    for(int i=1;i<=t;i++){
        scanf("%d/%d",&p,&q);
        val=(double)p/(double)q;
        if(gen(val)==-1){
            printf("Case #%d: impossible\n",i);
        }
        else
            printf("Case #%d: %d\n",i,ancestor(val));
    }
    return 0;
}
