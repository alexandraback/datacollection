#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 1010
using namespace std;



string zip[MAXN];
vector <int> e[MAXN];
typedef vector<int>::iterator iter;
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

void output();
void work(int index,int deep);



int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        printf("Case #%d: ",++cas);
        memset(vis,0,sizeof(vis));
        memset(fa,0,sizeof(fa));
        for (int i=0;i<MAXN;i++) e[i].clear();
        anss.clear();
        cin >> N >> M;
        for (int i=1;i<=N;i++) cin >> zip[i];
        for (int i=1;i<=M;i++){
            cin >> p1 >> p2;
            e[p1].push_back(p2);
            e[p2].push_back(p1);
        }
        for (int i=1;i<=N;i++) pos[i]=i;
        sort(pos+1,pos+N+1,cmp);
        for (int i=1;i<=N;i++)
            Y[pos[i]]=i;

