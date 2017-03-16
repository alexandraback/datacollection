#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
LL pow[100];
LL gcd(LL a,LL b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int main(){
    int test,fg1,fg2;
    LL A,B,c,d,gd;
    char t;
    scanf("%d",&test);
    pow[0] = 1;
    for(int i=1;i<50;i++) pow[i] = pow[i-1]*2;
    for(int i=0;i<test;i++){
        cin >> A >> t >> B;
        printf("Case #%d: ",i+1);
        gd = gcd(A,B);
        A/= gd;
        B/=gd;
        fg1 =0;
        for(int i=0;i<50;i++){
            if(B == pow[i]){
                c = i;
                fg1 = 1;
                break;
            }
        }
        if(fg1==0){
            printf("impossible\n");
            continue;
        }
        for(int i=0;i<50;i++){
            if(A < pow[i]){
                d= i-1;
                break;
            }
        }
        printf("%d\n",c-d);
    }
    return 0;
}
