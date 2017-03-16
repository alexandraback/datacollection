#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1000;

int N;
bool flag;
vector<int> edge[MAXN+2];
int ind[MAXN+2];
int color[MAXN+2];

bool dfs(int now, int par) {
    color[now] = par;
//    cout << now << ": " << color[now] << endl;///
    for (int i = 0; i < edge[now].size(); i++) {
        int cld = edge[now][i];
        if (color[cld] == par) {
            return false;
        }
        else if (!dfs(cld, par)) {
            return false;
        }
    }
    //color[now] = 0;
    return true;
}

int main() {
//    FILE *fin, *fout;    
//    fin = fopen("/home/liulixiang/workspace/TC/GCJR1C/A.in", "r");
//    fout = fopen("/home/liulixiang/workspace/TC/GCJR1C/A.out", "w");
    int T;
    scanf("%d\n", &T);
    for (int ca = 1; ca <= T; ca++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) edge[i].clear();
        for (int i = 0; i < N; i++) {
            color[i] = -1;
            scanf("%d", &ind[i]);
            for (int j = 0; j < ind[i]; j++) {
                int v;
                scanf("%d", &v); --v;
                edge[v].push_back(i);
            }
        }
        flag = false;
        
        for (int i = 0; i < N; i++) {
            if (ind[i] == 0) {
                if (!dfs(i, i)) {
                    flag = true;
                    break;
                }
            }
        }
    
        int ans = 0;
        printf("Case #%d: ", ca);
        if (flag) printf("Yes\n");
        else printf("No\n");
//        fprintf(fout, "Case #%d: %d\n", ca, ans);
    }
    
//    fclose(fin);
//    fclose(fout);
    return 0;
}

