#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10;
string postcode[MAXN],ans,tmp;

int N,M;
int res[MAXN][MAXN];

void clearinput(){
    memset(res,0,sizeof(int)*MAXN*MAXN);
}

int perm[MAXN];
int pass[MAXN];

string tt;
int parent[MAXN];
int res2[MAXN][MAXN];

void dfs(int u,int to,string now){
    if(u == to){
        tt = min(tt,now);
        return ;
    }

    for(int i=1;i<=N;i++){
        if(u == i) continue;
        if(res[u][i] && !parent[i] && res2[u][i] <= 0){
            if(pass[i]){
                parent[i] = u;
                dfs(i,to,now);
            }else{
                parent[i] = u;
                dfs(i,to,now+postcode[i]);
            }
        }
    }
}


void run2(){
    memset(pass,0,sizeof pass);
    tmp = postcode[perm[1]];
    pass[perm[1]] = true;


    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) res2[i][j] = 0;

    for(int i=1;i<=N-1;i++){
        memset(parent,0,sizeof parent);
        parent[perm[i]] = perm[i];

        tt = "X";
        dfs(perm[i],perm[i+1],"");
        tmp += tt;

        //for(int j=1;j<=N;j++) printf("parent[%d] = %d\n",j,parent[j]);


        int u = perm[i], v = perm[i+1];

        if(parent[v] == 0) return ;

        while(v != parent[v]){
            pass[v] = true;
            if(res2[parent[v]][v] == 0){
                res2[parent[v]][v] = 1;
                res2[v][parent[v]] = -1;
            }
            v = parent[v];
        }

        /*printf("[%d to %d] : %s\n",perm[i],perm[i+1],tt.c_str());
        for(int j=1;j<=N;j++){
                for(int k=1;k<=N;k++) printf("[%d]",res2[j][k]);
                printf("\n");
        }
        printf("\n\n");*/
    }
    ans = min(ans,tmp);
}

void run(){
    clearinput();

    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++) cin >> postcode[i];
    for(int i=1;i<=M;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        res[a][b] = res[b][a] = true;
    }

    for(int i=1;i<=N;i++) perm[i] = i;

    ans = "X";
    do{
        //for(int i=1;i<=N;i++) printf("[%d]",perm[i]); printf("\n");
        run2();
    }while(next_permutation(&perm[1],&perm[N+1]));

    cout << ans << "\n";
}

int main(){
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);

    int T; scanf("%d",&T);
    for(int i=1;i<=T;i++){
        printf("Case #%d: ",i);
        run();
    }
    return 0;
}
