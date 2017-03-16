#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <cassert>
#include <set>
using namespace std;


const int N=500;

string c,j;

vector<string> a,b;
void dfs(int s,int n,string now) {
    if (s>=n) {
        a.push_back(now);
        return;
    }
    if (c[s]=='?') {
        for (int i=0;i<10;i++) {
            string nn=now+char('0'+i);
            dfs(s+1,n,nn);
        }
    }
    else {
        dfs(s+1,n,now+c[s]);
    }
}

void dfs2(int s,int n,string now) {
    if (s>=n) {
        b.push_back(now);
        return;
    }
    if (j[s]=='?') {
        for (int i=0;i<10;i++) {
            string nn=now+char('0'+i);
            dfs2(s+1,n,nn);
        }
    }
    else {
        dfs2(s+1,n,now+j[s]);
    }
}
int calc(string s) {
    int ret=0;
    for (int i=0;i<s.size();i++) {
        assert(s[i]>='0'&&s[i]<='9');
        ret=ret*10+s[i]-'0';
    }
    return ret;
}
void solve() {
    int n=c.size();
    a.clear();
    b.clear();
    dfs(0,n,"");
    dfs2(0,n,"");
    int dif=0x3f3f3f3f;
    string p="0",q="0";
    for (int i=0;i<a.size();i++) {
        for (int j=0;j<b.size();j++) {
            int aa=calc(a[i]);
            int bb=calc(b[j]);
            int now=abs(aa-bb);
            if (now<dif) {
                dif=now;
                p=a[i];
                q=b[j];
            }
            else if (now==dif) {
                if (a[i]<p) {
                    p=a[i];
                    q=b[j];
                }
                else if (p==a[i]) {
                    if (b[j]<q) {
                        q=b[j];
                    }
                }
            }
        }
    }
    cout<<p<<" "<<q<<endl;
}
int main () {
    freopen("hehe.txt","r",stdin);
    freopen("cao.txt","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        cin>>c>>j;
        static int cas=1;
        cout<<"Case #"<<cas++<<": ";
        solve();
    }
    return 0;
}
