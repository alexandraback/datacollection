#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;

const int mx=1e3+10;
char s[mx];

int main(){
    freopen("al.in","r",stdin);
    freopen("al.out","w",stdout);
    int t,n,ans,c;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d %s",&n,s);
        ans=c=0;
        for(int i=0;i<=n;i++){
            if(s[i]=='0')continue;
            if(c<i){
                ans+=i-c;
                c=i;
            }
            c+=s[i]-'0';
        }
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
