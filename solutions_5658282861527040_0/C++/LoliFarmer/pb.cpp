#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
char str[1024];
int main(){
    int T, n, ans, L;
    scanf("%d",&T);
    int A,B,K;
    for(int f=1;f<=T;f++){
        scanf("%d%d%d",&A,&B,&K);
        ans = 0;
        for(int i=0;i<A;i++){
            for(int j=0;j<B;j++){
                if((i&j) < K){
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n", f, ans);
    }
}
