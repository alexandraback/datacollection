#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pr;

const int maxn = 100005;
char s[200];

void solve(){
    scanf("%s",s);
    int len=strlen(s);
    int cnt=0;
    for (int i=1;i<len;i++){
        if (s[i]!=s[i-1]) cnt++;
    }
    if (s[len-1]=='-') cnt++;
    printf("%d\n",cnt);
}

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++){
        printf("Case #%d: ",kase);
        solve();
    }
    return 0;
}
