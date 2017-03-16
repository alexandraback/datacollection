#include <cstdio>
#include <iostream>
using namespace std;
int memo[10];
void init(){
    for (int i=0;i<10;++i) memo[i]=0;
}
void noted(int x){
    while (x>0){
        memo[x%10]=1;
        x/=10;
    }
}
bool done(){
    bool ret=1;
    for (int i=0;i<10;++i) ret&=memo[i];
    return ret;
}
void solve(){
    printf(" ");
    int n;
    scanf("%d",&n);
    if (n==0) printf("INSOMNIA\n");
    else{
        init();
        for (int i=1;;++i){
            noted(i*n);
            if (done()){
                printf("%d\n",i*n);
                return;
            }
        }
    }
}

int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d:",test);
        solve();
    }
    return 0;
}
