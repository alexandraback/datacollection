#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,casenum=1;
    char str[1010];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",str);
        int ans=0;
        int now=0;
        for(int i=0;i<=n;i++){
            if( str[i]!='0' && now < i ){
                ans += i - now;
                now += i - now;
            }
            now += str[i]-'0';
        }
        printf("Case #%d: %d\n",casenum++,ans);
    }
    return 0;
}
