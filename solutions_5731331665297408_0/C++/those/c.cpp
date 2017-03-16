#include<stdio.h>
#include<map>
#include<queue>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back

bool vis[100];
string ans, s[100], cur;
int n,m;
bool adj[100][100];

int run(int *per, int i){
//    printf("run %d\n", i);
    if (i == n-1){
        return n-1;
    }else{
        int p = i;
 //       printf("can go? %d %d -> %d\n", per[i], per[p+1], adj[per[i]][per[p+1]]);
        while (p<n-1 && adj[per[i]][per[p+1]]){
   //         printf(">> p = %d\n", p);
            int np = run(per, p+1);
  //          printf("return: %d\n", np);
            if (np == p) break;
            p = np;
            //printf("before\n");
           // printf("can go? %d %d -> %d\n", per[i], per[p+1], adj[per[i]][per[p+1]]);
        }
        return p;
    }
}

int main(){
    int ca; scanf("%d",&ca);
    FOE(tca, 1, ca){
        scanf("%d%d", &n, &m);
        FOR(i,0,n){
            char ss[100]; scanf("%s",ss);
            s[i] = ss;
        }
        CLR(adj);
        FOR(i,0,m){
            int x, y; scanf("%d%d",&x,&y); x--; y--;
            adj[x][y]=adj[y][x]=true;
        }
        /*
        int st = 0;
        FOR(i,1,n){
            if (s[st] > s[i]) st = i;
        }
        */
        int per[100];
        ans = "";
        FOR(i,0,n) per[i]=i;
        do{
            //if (per[0]!=4 || per[1]!=1 || per[2]!=0 || per[3]!=2) continue;
            //FOR(i,0,n) printf("%d ",per[i]); puts("");
            int ret = run(per, 0);
            if (ret == n-1){
                string ss = "";
                FOR(i,0,n) ss += s[per[i]];
                //printf("%s\n", ss.c_str());
                if (ans=="" || ss < ans) ans = ss;
            }
        }while (next_permutation(per, per+n));

        printf("Case #%d: %s\n", tca, ans.c_str());
    }
    return 0;
}
