#include<bits/stdc++.h>
using namespace std;
int T,n;
char s[1234];
int main(){
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    scanf("%d",&T);

    for(int ti=1;ti<=T;ti++){

        printf("Case #%d: ",ti);
        scanf("%s",s);
        int l=strlen(s);
        string ans;
        ans=ans+s[0];
        for(int i=1;i<l;i++) if (s[i]>=ans[0]) ans=s[i]+ans;
        else ans=ans+s[i];
        cout<<ans<<endl;
    }


}
