#include<stdio.h>
#include<utility>
#define ll long long
#define pr pair<long long,long long>
using namespace std;
long long gcd(long long x,long long y){
    if(x==0)return y;
    return gcd(y%x,x);
}
long long a,b;
ll ex[44];
int check(ll v){
    int i;
    for(i=0;i<41;i++){
        if(ex[i]==v)return i;
        if(ex[i]>v)return 0;
    }
    return 0;
}
int gex(ll v){
    int i;
    for(i=1;i<41;i++){
        if(ex[i]>v)return i-1;
    }
}
void proc(int xx){
    scanf("%I64d/%I64d",&a,&b);
    int i;
    ex[0]=1;
    for(i=1;i<44;i++)ex[i]=ex[i-1]*2;
    ll gd=gcd(a,b);
    a/=gd;
    b/=gd;
    if(!check(b)){
        printf("Case #%d: impossible\n",xx);
        return;
    }
    printf("Case #%d: %d\n",xx,check(b/ex[gex(a)]) ) ;
    //printf("%I64d %I64d",a,b);
}
int main(){
    int tx;
    scanf("%d",&tx);
    int i;
    for(i=1;i<=tx;i++)proc(i);
    return 0;
}
