#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>

typedef long long ll;

int t, b, cnt;
int m;
bool ok[25][25];
bool flag, o;
int st ;
bool map[25][25];

bool check(int x, int y){
    if(x == y) return false;
    if(map[x][y] || map[y][x]) return false;
    return true;
}

void f(){
    memset(map, 0, sizeof map);
    for(int i=1; i<=b; i++) for(int j=1; j<=b; j++) map[i][j] = ok[i][j];
    for(int k=1; k<=b; k++){
        for(int i=1; i<=b; i++){
            for(int j=1; j<=b; j++)if(map[i][k] && map[k][j]){
                map[i][j] = 1;
            }
        }
    }
}

void dfs(int now, std:: vector<int> v, int st){
    if(flag){
        return ;
    }
    if(now == b){
        int size = v.size();
        for(int i=1; i<size; i++){
            ok[v[i-1]][v[i]]=1;
            for(int j=1; j<=b; j++) for(int k=1; k<=b; k++) if(map[j][v[i-1]] && map[v[i]][k]) map[j][k]=1;
        }
        cnt ++;
        if(cnt == m){
            flag = true;
        }
        return;
    }
    if(flag){
        return ;
    }
    int size = v.size();
    for(int i=1; i<=b; i++) if((!(st&(1<<(i-1)))) && check(now, i)){
        std::vector<int> vv;
        for(int j=0; j<size; j++) vv.push_back(v[j]);
        vv.push_back(i);
        dfs(i, vv, st|(1<<(i-1)));
    }
}
int main(){
    freopen("B-small-attempt3.in", "r", stdin);
    freopen("B3.out", "w", stdout);
    scanf("%d", &t);
    for(int ca=1; ca<=t; ca++){
        memset(map, 0, sizeof map);
        scanf("%d%d", &b, &m);
        memset(ok, 0, sizeof ok);
        flag = 0;
        cnt =0 ;
        std::vector<int>v;
        v.push_back(1);
        st=1;
        dfs(1, v, 1);
        if(flag){
            printf("Case #%d: POSSIBLE\n", ca);
            for(int i=1; i<=b; i++){
                for(int j=1; j<=b; j++){
                    ok[i][j]?putchar('1'):putchar('0');
                }
                putchar('\n');
            }
        }else{
            printf("Case #%d: IMPOSSIBLE\n", ca);
        }
    }
    return 0;
}
