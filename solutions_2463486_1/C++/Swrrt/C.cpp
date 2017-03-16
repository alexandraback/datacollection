#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
long long A[10000005];
int gs=0;
int ST[20];
inline bool IsPal(long long t){
    int len=0;
    while(t){
        ST[++len]=t%10;
        t/=10;
    }
    for(int i=1,j=len;i<j;i++,j--)
        if(ST[i]!=ST[j])return 0;
    return 1;
}
int main(){
    int i,j,T,tt;
    tt=0;
    freopen("C.out","w",stdout);
    scanf("%d",&T);
    A[1]=0;gs=1;
    for(i=1;i<=10000000;i++){
        long long t=((long long)i)*i;
        if(IsPal((long long)i)&&IsPal(t))A[++gs]=t;
    }
//    sort(A+1,A+1+gs);
    while(T--){
        tt++;
        long long L,R;
        scanf("%I64d%I64d",&L,&R);
        printf("Case #%d: ",tt);
        printf("%d\n",upper_bound(A+1,A+1+gs,R)-lower_bound(A+1,A+1+gs,L));
    }
    return 0;
}

