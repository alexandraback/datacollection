#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000000;

queue<int> q;

int vis[maxn+10];

int T,n;

vector<int> td;

int op(int x)  {
    td.clear();
    while (x) {
        td.push_back(x%10);
        x /= 10;
    }
    //reverse(td.begin(),td.end());
    int ts = 0;
    for (int i = 0;i < td.size(); i++) {
        ts = ts * 10 + td[i];
    }
    return ts;
}

int main() {
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d",&T);
    for (int kase = 1;kase <= T; kase++) {
           scanf("%d",&n);
           memset(vis,0,sizeof(vis));
           while (!q.empty()) q.pop();
           q.push(1); vis[1] = 1;
           while (!q.empty()) {
                  int t = q.front(); q.pop();
                  //cout<<t<<endl;
                  if (t == n) break;
                  if (!vis[t+1]) {
                        vis[t+1] = vis[t]+1;
                        q.push(t+1);
                  }
                  int w = op(t);
                  if (!vis[w]) {
                        vis[w] = vis[t]+1;
                        q.push(w);
                  }
           }
          /* for (int i =1;i <= n; i++)
                printf("%d %d\n",i,vis[i]);
           */
           printf("Case #%d: %d\n",kase,vis[n]);
    }
    return 0;
}
