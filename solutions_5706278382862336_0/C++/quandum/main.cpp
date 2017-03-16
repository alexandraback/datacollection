#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <cmath>
#include <iomanip>
#define _USE_MATH_DEFINES
using namespace std;
long long gcd(long long a,long long b){
    while (a>0&&b>0){
        if (a>b)a=a%b;
        else b=b%a;
    }
    return (a+b);
}
void reduce(long long &a, long long &b){
    long long g=gcd(a,b);
    a=a/g; b=b/g;
}
long long t,m,a,b;
void process(){
    if (b==0||a==0||a>b) {printf("impossible"); return;}
    reduce(a,b);
    if (a==1&&b==1) {printf("1"); return;}
    int n=log2l(b+0.1);
    if ((((long long)1)<< n)!=b)
        {printf("impossible"); return;}

    int rs=-1;
    for (int i=0;i<n;i++) if (((a>>i)&1)>0){
        rs=i;
    }
    if (rs<0)printf("impossible");
    else{
        rs=n-rs; printf("%d",rs);
    }
}
int main(){

    int test,ntest;
    freopen("A-small-attempt2.in","r",stdin); freopen("A-small-attempt2.out","w",stdout);
    scanf(" %d",&ntest); long long g;
    for (test=1;test<=ntest;test++){
        scanf("\n%lld/%lld",&a,&b);
        if (test>1) printf("\n");
        printf("Case #%d: ",test);
        process();
    }
    fclose(stdin); fclose(stdout);
    return 0;
}
