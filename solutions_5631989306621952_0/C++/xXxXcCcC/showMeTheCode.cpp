#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pr;

void solve(){
    char s[1005];
    scanf("%s",s);
    int len=strlen(s);
    stack<char>ss;
    vector<char>v;
    ss.push(s[0]);
    for (int i=1;i<len;i++){
        if (s[i]>=ss.top()){
            ss.push(s[i]);
        }
        else {
            v.push_back(s[i]);
        }
    }
    while(!ss.empty()){
        putchar(ss.top());
        ss.pop();
    }
    for (int i=0;i<v.size();i++){
        putchar(v[i]);
    }
    putchar('\n');
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
