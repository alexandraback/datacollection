#include <bits/stdc++.h>
using namespace std;


const int N  = 1005;
int head[N];

struct point{
    int x, y,  next;
    point(){};
    point(int _x, int _y, int _next){
        x = _x, y = _y, next = _next;
    }
}p[N];
struct favpair{
    int x, y;
    favpair(){};
    favpair(int _x, int _y){
        x = _x, y = _y;
    };
};
int ans;
int fav[N];
int no;
int vis[N], dis[N];
vector<int>backedge[N];
void init(){
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    fill(backedge, backedge + N, vector<int>() );
    no = 0; ans = 0;
}
void add(int x, int y){
    p[no] = point(x, y, head[x]);   head[x]=no++;
}

void bfs(int x){
    int s = x;
    queue<int>q;
    q.push(x);
    vis[x] = true;
    bool inthisloop[N];
    memset(inthisloop, 0, sizeof(inthisloop));
    while(!q.empty()){
        x = q.front();  q.pop();
        for(int i = head[x]; i != -1; i = p[i].next){
            int y = p[i].y;
            if(dis[y])  continue;
            inthisloop[y] = true;
            if(!vis[y]){
                vis[y] = true;
                q.push(y);
            }
        }
    }
    dis[s] = 1;
    q.push(s);
    while(!q.empty()){
        x = q.front();  q.pop();
        for(int i = head[x]; i != -1; i = p[i].next){
            int y = p[i].y;
            if(!inthisloop[y]) continue;
            //printf("?y:%d %d\n", y, dis[y]);
            if(dis[y] == 0){
                dis[y] = dis[x] + 1;
                q.push(y);
            }else{
                //printf("%d %d %d %d %d\n",x, y, dis[x], dis[y], dis[x] - dis[y] + 1);
                ans = max(ans, dis[x] - dis[y] + 1);
            }
        }
    }
    //printf("!%d\n", ans);
}

int bfs(int x, int y){
    queue<int>q;
    q.push(x);
    dis[x] = 1;
    int len = 1;
    while(!q.empty()){
        x = q.front();  q.pop();
        for(int i = 0; i < backedge[x].size(); i++){
            int st = backedge[x][i];
            if(st == y) continue;
            dis[st] = dis[x] + 1;
            len = max(dis[st], len);
            q.push(st);
        }
    }
    return len;
}
int main(){
            freopen("A-large.in", "r", stdin);
    freopen("large.out", "w", stdout);
    int tc, TC;
    scanf("%d", &TC);
    for(tc = 1;  tc <= TC; tc++){
        int n;
        scanf("%d", &n);
        init();

        for(int i = 1; i <= n; i++){
            scanf("%d", &fav[i]);
            add(i, fav[i]);
            backedge[fav[i]].push_back(i);
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                bfs(i);
            }
        }
        vector<struct favpair>favp;
        favp.clear();
        for(int i = 1; i <= n; i++){
            if(fav[fav[i]] == i){
                if(fav[i] > i)
                    favp.push_back(favpair(i, fav[i]));
            }
        }
        memset(dis, 0, sizeof(dis));
        int temp = 0;
        for(int i = 0; i < favp.size(); i++){
            int x = favp[i].x;  int y = favp[i].y;
            temp += bfs(x, y);
           // printf("%d %d\n", x, temp);
            temp += bfs(y, x);
        }

        printf("Case #%d: %d\n",tc, max(ans, temp));

    }
    return 0;
}
