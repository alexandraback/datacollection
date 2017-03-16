#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100;
string zip[MAXN];
vector <int> e[MAXN];
typedef vector<int>::iterator iter;
int _;
int N,M;
int cas=0;
int p1,p2;
int pos[MAXN];
int Y[MAXN];
int ans[MAXN];
bool flag = false;
bool vis[MAXN];
int fa[MAXN];

bool cmp(int a,int b){
    return zip[a]<zip[b];
}

bool cmp2(int a,int b){
    return Y[a]<Y[b];
}

string anss;

void output(){
    string rul;
    for (int i=1;i<=N;i++)
            rul+= zip[ans[i]];
    if (anss.size()==0) anss = rul; else anss = min(anss,rul);
}

void work(int index,int deep){
    if (deep>N){
        output();
    }
    for (iter k=e[ans[index]].begin();k!=e[ans[index]].end();k++){
        if (vis[*k]) continue;
        vis[*k]=true;
        ans[deep]=*k;
        fa[deep]=index;
        work(deep,deep+1);
        if (flag) return;
        vis[*k]=false;
    }
    if (fa[index]) work(fa[index],deep);
}



int main(){
    //freopen("C-small-attempt0.in","r",stdin);
    //freopen("C-small-attempt0.out","w",stdout);
    cin >> _;
    while(_--){
        for (int i=0;i<MAXN;i++) e[i].clear();
        anss.clear();
        memset(vis,0,sizeof(vis));
        memset(fa,0,sizeof(fa));
        cin >> N >> M;
        for (int i=1;i<=N;i++) cin >> zip[i];
        for (int i=1;i<=M;i++){
            cin >> p1 >> p2;
            e[p1].push_back(p2);
            e[p2].push_back(p1);
        }
        for (int i=1;i<=N;i++) pos[i]=i;
        sort(pos+1,pos+N+1,cmp);
        for (int i=1;i<=N;i++) Y[pos[i]]=i;
        //for (int i=1;i<=N;i++) sort(e[i].begin(),e[i].end(),cmp2);
        flag = false;
        vis[pos[1]]=true;
        ans[1]=pos[1];
        work(1,2);
        cout << "Case #"<< ++cas << ": " << anss << endl;
    }
}
