#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
char s[MAXN];
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t; cin>>t;
    for(int cs=1; cs<=t; cs++){
        int n; cin>>n>>s;
        int sum=0, ans=0;
        for(int i=0; i<=n; i++){
            if(sum<i){
                ans+=i-sum;
                sum=i;
            }
            sum+=s[i]-'0';
        }
        printf("Case #%d: %d\n",cs,ans);
    }
    return 0;
}
