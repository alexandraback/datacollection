#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
string s[200],t;
int n,ans,now;
int st[100],v[200],ch[100];
void dfs(int k){
    if (k == n+1) {
        ans++;
        return;
    }
    {
        for (int i = 1; i <= n; i++)if (!v[i]){
            if (s[i][0]-'a'!=now) ch[now]++;
            else ch[now]--;
            for (int j = 0; j < s[i].length();j++){
                ch[s[i][j]-'a']++;
                if (j!=0) ch[s[i][j-1]-'a']++;
            }
            int tnow = now;
            now = s[i][s[i].length()-1]-'a';
            v[i] = 1;
            int flag = 1;
            for (int j = 0; j < 26; j++)
                if (ch[j]>2) {flag = 0;break;}
            if (flag) {
                //cout<<k<<' '<<i<<endl;
                dfs(k+1);
            }
            v[i] = 0;
            now = tnow;
            if (s[i][0]-'a'!=now) ch[now]--;
            else ch[now]++;
            for (int j = 0; j < s[i].length();j++){
                ch[s[i][j]-'a']--;
                if (j!=0) ch[s[i][j-1]-'a']--;
            }
        }
    }
}
int main()
{
    freopen("B1.in","r",stdin);
    freopen("B1.txt","w",stdout);
    int T,i,j;
    cin>>T;
    for (int cas = 1; cas <= T; cas++){
        cin>>n;
        ans = 0;
        for (i = 1; i <= n; i++) {
            cin>>t;
            s[i]="";
            s[i] = s[i]+t[0];
            for (j = 1; j < t.length(); j++)
                if (s[i][s[i].length()-1]!=t[j]) s[i] = s[i]+t[j];
            //cout<<s[i]<<endl;
            //cin>>s[i];
        }
        sort(s,s+n);
        memset(st,0,sizeof(st));
        memset(ch,0,sizeof(ch));
        memset(v,0,sizeof(v));
        for (i = 1; i <= n; i++){
            if (st[s[i][0]-'a']==0)st[s[i][0]-'a'] = i;
        }
        //for (i = 0; i < 26; i++) cout<<st[i]<<' ';
        for (i = 1; i <= n; i++){
            for (int j = 0; j < s[i].length();j++){
                ch[s[i][j]-'a']++;
                if (j!=0) ch[s[i][j-1]-'a']++;
            }
            int tnow = now;
            now = s[i][s[i].length()-1]-'a';
            v[i] = 1;
            int flag = 1;
            for (int j = 0; j < 26; j++)
                if (ch[j]>2) {flag = 0;break;}
            if (flag) {
                //cout<<k<<' '<<i<<endl;
                dfs(2);
            }
            v[i] = 0;
            now = tnow;
            for (int j = 0; j < s[i].length();j++){
                ch[s[i][j]-'a']--;
                if (j!=0) ch[s[i][j-1]-'a']--;
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
