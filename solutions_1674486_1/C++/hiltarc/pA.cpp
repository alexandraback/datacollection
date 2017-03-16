#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
#include<limits>
#include<utility>
#define PB push_back
#define MP make_pair
#define _F first
#define _S second
#define PP system("PAUSE");

using namespace std;

vector<int> E[2000];
vector<int> revE[2000];
bool vis[2000];

void init(void){
    for(int i = 0; i < 2000; i++){
        E[i].clear();
        revE[i].clear();
        vis[i] = false;
        }
    return;
    }

bool DFS(int now){
    vis[now] = true;
    for(int i = 0; i < E[now].size(); i++){
        int v = E[now][i];//printf("%d=>%d\n", now, v);printf("vis:%d\n", vis[v]);
        if(vis[v]) return true;
        if(DFS(v)) return true;
        }//printf("=>%d\n", now);
    return false;
    }

int main(void){
    freopen("A-large (1).in", "r", stdin);
    freopen("A-large (1).out", "w", stdout);

    int T;
    int N;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        printf("Case #%d: ", i);
        init();
        scanf("%d", &N);
        for(int j = 1; j <= N; j++){
            int M;
            scanf("%d", &M);
            for(int k = 0; k < M; k++){
                int temp;
                scanf("%d", &temp);
                E[j].PB(temp);
                revE[temp].PB(j);
                }
            }
        bool yes = false;
        for(int j = 1; j <= N; j++){
            for(int k = 0; k < 2000; k++) vis[k] = false;
            if(DFS(j)){
                yes = true;
                puts("Yes");
                break;
                }
            }
        if(!yes) puts("No");
        }

    return 0;
    }
