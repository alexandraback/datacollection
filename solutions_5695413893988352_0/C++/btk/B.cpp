#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
typedef __int128 INT;

struct node{
    string s,t;
    INT diff()const{
        INT a=0,b=0;
        for(auto& it : s)(a*=10)+=(it-'0');
        for(auto& it : t)(b*=10)+=(it-'0');
        return (a-b>=0)?a-b:b-a;
    }
    bool operator<(const node &o)const{
        INT v = diff();
        INT u = o.diff();
        if(v==u){
            if(s==o.s)return t<o.t;
            else return s<o.s;
        }
        else return v<u;
    }
    node(string s,string t):s(s),t(t){}
};
node calc(string s,string t){
    int n=s.size();
    int i=0;
    while(i<n&&s[i]==t[i])i++;
    if(i==n)return node(s,t);
    if(s[i]>t[i]){
        for(auto& it : s)if(it=='?')it='0';
        for(auto& it : t)if(it=='?')it='9';
    }
    else{
        for(auto& it : s)if(it=='?')it='9';
        for(auto& it : t)if(it=='?')it='0';
    }
    return node(s,t);
}
void solve(){
    string S,T;
    cin >> S >> T;
    int n =S.size();
    node res(S,T);
    string s=S,t=T;
    for(auto& it : res.s)if(it=='?')it='0';
    for(auto& it : res.t)if(it=='?')it='9';
    for(int i = 0; i < n; i++){
             if(S[i]==T[i]&&S[i]=='?'){
                 s[i]='1',t[i]='0';
                 res=min(res,calc(s,t));
                 s[i]='0',t[i]='1';
                 res=min(res,calc(s,t));
                 s[i]='0',t[i]='0';
             }
        else if(S[i]=='?'){
                 if(T[i]!='9'){
                     s[i]=T[i]+1;
                     res=min(res,calc(s,t));
                 }
                 if(T[i]!='0'){
                     s[i]=T[i]-1;
                     res=min(res,calc(s,t));
                 }
                 s[i]=T[i];
        }
        else if(T[i]=='?'){
                 if(S[i]!='9'){
                     t[i]=S[i]+1;
                     res=min(res,calc(s,t));
                 }
                 if(S[i]!='0'){
                     t[i]=S[i]-1;
                     res=min(res,calc(s,t));
                 }
                 t[i]=S[i];
        }
        else if(S[i]==T[i])continue;
        else {
            break;
        }
    }
    res=min(res,calc(s,t));

    cout << res.s << " " << res.t;
}

int main() {
    int T; cin >> T;
    for(int i = 1; i <= T; i++){
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
