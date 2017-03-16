#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;

int arrow[1005],T,N,cap[1005];
bool sudah[1005],bisa[1005],dua[1005];
vector<int> edge[1005];

int dfs(int node,int depth) {
    int maks = depth;
    for (int i=0;i<edge[node].size();++i) {
        maks = max(maks,dfs(edge[node][i],depth+1));
    }
    return maks;
}

int main() {
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%d",&N);
        memset(bisa,0,sizeof(bisa));
        memset(dua,0,sizeof(dua));
        
        for (int i=1;i<=N;++i) {
            scanf("%d",&arrow[i]);
            edge[i].clear();
        }
        
        int jawab = 0;
        for (int i=1;i<=N;++i) {
            memset(sudah,0,sizeof(sudah));
            int idx = i;
            int number = 0;
            while (!sudah[idx]) {
                sudah[idx] = true;
                cap[idx] = ++number;
                idx = arrow[idx];
            }
            
            jawab = max(jawab,number+1-cap[idx]);
            if (number+1-cap[idx] == 2) {
                dua[idx] = bisa[idx] = true;
                dua[arrow[idx]] = bisa[arrow[idx]] = true;
            }
        }
        
        for (int i=1;i<=N;++i) {
            if (dua[i]) continue;
            edge[arrow[i]].push_back(i);
        }
        
        int temp = 0;
        for (int i=1;i<=N;++i) {
            if (!dua[i]) continue;
            temp += dfs(i,1);
        }
        jawab = max(temp,jawab);
        
        printf("Case #%d: %d\n",l,jawab);
    }
    return 0;
}
