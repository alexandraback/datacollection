#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <bitset>
using namespace std;


string s[100];
const int N=100;
int n;

vector<int>pos[50];
bool check(string str){
    set<char>se;
    se.insert(str[0]);
    for (int i=1;i<str.size();i++){
        if (str[i]==str[i-1]) continue;
        if (se.count(str[i])) return false;
        se.insert(str[i]);
    }
    return true;
}
int ans=0;
bool vis[N];
int num[N];
bool ok(){
    string ret="";
    for (int i=1;i<=n;i++)
        ret+=s[num[i]];
    return check(ret);
}
void dfs(int dep){
    if (dep>n){
        if (ok()){
            ans++;
        }
        return ;
    }
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            vis[i]=true;
            num[dep]=i;
            dfs(dep+1);
            vis[i]=false;
        }
    }
}
int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,cas=1;
    cin>>T;
    while (T--){
        cin>>n;
        bool ok=true;
        for (int i=0;i<30;i++) pos[i].clear();
        for (int i=1;i<=n;i++){
            cin>>s[i];
            string::iterator it=unique(s[i].begin(),s[i].end());
            s[i].erase(it,s[i].end());
            ok&=check(s[i]);
            pos[int(s[i][0]-'a')].push_back(i);
        }
        if (!ok){
            printf("Case #%d: %d\n",cas++,0);
            continue;
        }
        memset(vis,0,sizeof vis);
        ans=0;
        dfs(1);
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}



