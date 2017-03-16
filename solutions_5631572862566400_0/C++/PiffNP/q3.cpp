#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define LEN 1200
int map[LEN];
int v[LEN];
int degree[LEN];
int ans, x;
vector<int> edge[LEN];
int dfs(int cur, int label){
    int k = map[cur];
    if(v[k] == -1){
    } else if (v[k] == 0){
        v[cur] = label;
        dfs(k, label + 1);
    } else if (v[k] > 0){
        int t = label - v[k] + 1;
        if(t > ans)
            ans = t, x = cur;
    }
    v[cur] = -1;
    return 0;
}

int dfs2(int cur){
    int ret = 0;
    for(int j = 0; j < edge[cur].size(); j++){
        if(edge[cur][j] == map[cur])
            continue;
        int k = dfs2(edge[cur][j]);
        if(ret < k)
            ret = k;
    }
    return ret + 1;
}

int main(){
    int t;
    FILE *fp1, *fp2;
    if((fp1 = fopen("a.in", "r")) == NULL)
        return 1;
    fp2 = fopen("a.out", "w");
    fscanf(fp1, "%d", &t);
    for(int i = 0; i < t; i++){
        memset(map, 0, sizeof(map));
        memset(v, 0, sizeof(v));
        memset(degree, 0, sizeof(degree));
        int n;
        fscanf(fp1, "%d", &n);
        for(int j = 0; j < n; j++)
            edge[j].clear();
        for(int j = 0; j < n; j++){
            int tmp;
            fscanf(fp1, "%d", &tmp);
            map[j] = tmp - 1;
            edge[tmp - 1].push_back(j);
        }
        ans = 0;
        for(int j = 0; j < n; j++)
            dfs(j, 1);
        //case 2
        for(int j = 0; j < n; j++)
            if(map[map[j]] == j && j < map[j]){
                int t1 = dfs2(j);
                int t2 = dfs2(map[j]);
                if(ans < t1 + t2)
                    ans = t1 + t2;
            }
        fprintf(fp2, "Case #%d: %d\n", i + 1, ans);
    }
    return 0;
}
