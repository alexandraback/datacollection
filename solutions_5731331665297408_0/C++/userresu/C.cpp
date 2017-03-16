#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s[100];
vector<vector<int> > con(101);
bool used[100];
int order[100];
int cnt=1;

int N,M;

bool vis[100];
int cur;
void dfs (int i) {
    for (int j=0;j<con[i].size();++j) {
        int x=con[i][j];
        if (x==order[cur]) {
            vis[x]=1;
            ++cur;
            dfs(x);
            j=-1;
        }
    }
}

string best="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
void search (int i) {
    if (i==N+1) {
        for (int j=1;j<=N;++j) vis[j]=0;
        vis[order[1]]=1;
        cur=2;
        dfs(order[1]);
        bool ok=1;
        for (int j=1;j<=N;++j) if (!vis[j]) {
            ok=0;
            break;
        }
        if (ok) {
            string t="";
            for (int j=1;j<=N;++j) t += s[order[j]];
            best=min(best,t);
        }
        return;
    }
    for (int j=1;j<=N;++j) if (!used[j]) {
        used[j]=1;
        order[cnt]=j;
        ++cnt;
        search(i+1);
        --cnt;
        used[j]=0;
    }
}
int T;
int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> T;
    for (int z=1;z<=T;++z ){
    cin >> N >> M;
    best="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    cnt=1;
    for (int i=1;i<=N;++i) con[i].clear(),used[i]=0;
    for (int i=1;i<=N;++i) cin >> s[i];
    for (int i=1;i<=M;++i) {
        int x,y;
        cin >> x >> y;
        con[x].push_back(y);
        con[y].push_back(x);
    }
    search(1);
    cout << "Case #" << z << ": " << best << "\n";
}
    return 0;
}
