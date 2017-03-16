#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long ans[1000005],x;
int isPalidrome(long long a){
    int str[100];
    int len=0,i;
    while(a != 0){
        str[len] = a%10;
        a/=10;
        len++;
    }
    for(i=0;i<len;i++){
        if(str[i] != str[len-i-1])return 0;
    }
    return 1;

}
void make_ans(){
    int i;
    long long tmp;
    x = 0;
    for(i=1;i<=10000000;i++){
        tmp = i;
        if(isPalidrome(tmp) == 1 && isPalidrome(tmp*tmp) == 1){
            ans[x] = tmp*tmp;
            //printf("%lld\n",tmp*tmp);
            x++;
        }
    }
}
int main (){
    int T;
    long long a,b;
    int cnt;
    int i,ca;
    make_ans();
    //printf("%d\n",x);
    scanf("%d",&T);
    for(ca=1;ca<=T;ca++){
        scanf("%lld%lld",&a,&b);
        cnt = 0;
        for(i=0;i<x;i++){
            if(ans[i] >= a && ans[i] <= b)cnt++;
        }
        printf("Case #%d: %d\n",ca,cnt);
    }
    return 0;
}
