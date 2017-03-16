#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    freopen("1B2.in","r",stdin);
    freopen("out","w",stdout);
    int t=0,t2=1;
    scanf("%d",&t);
    while(t--){
               
               int n;
               int cake[1000];
               scanf("%d",&n);
               for(int i = 0; i < n; ++i){
                       scanf("%d",cake+i);
                       }
               int ans = 1001;
               for(int i = 1; i < 1001; ++i){
                       int cnt = 0;
                       for(int j = 0; j < n; ++j){
                               cnt += cake[j]/i + (cake[j]%i != 0) - 1;
                               }
                       ans = min(ans, cnt + i);
                       }
               
               printf("Case #%d: %d\n", t2++, ans);
               }
    }