#include<stdio.h>
#include<string.h>
using namespace std;
char test[2000001];
int pop[8] = {1,10,100,1000,10000,100000,1000000,10000000};
int A,B;
int countDigit(int i){
    int ans = i>0;
    while((i/=10)>0)  ans++;
    return ans;
}
int qq(int t){
    if(t < 10)  return 1;
    int ans = 0,digit = countDigit(t),tmp;
    int yy = pop[digit-1];
    test[t] = 1;
    for(int i=0;i<digit-1;++i){
        tmp = t/yy;
        t = (t%yy)*10+tmp;
        if(t<A || t>B)  continue;
        if(test[t] == 0){
            test[t] = 1;
            ans++;
        }
    }
    return ans +1;
}
int main(){
    long long ans;
    int T,y;
    scanf("%d",&T);
    for(int c= 1;c<=T;c++){
        ans = 0;
        memset(test,0,sizeof(test));
        scanf("%d %d",&A,&B);
        for(int i=A;i<=B;++i){
            if(test[i]) continue;
            y = qq(i);
            ans += (long long)(y*(y-1)/2);
        }
        printf("Case #%d: %lld\n",c ,ans );
    }
}
