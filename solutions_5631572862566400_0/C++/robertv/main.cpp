#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
template <class T> T sqr(T x) { return x*x; }

int T, N;
int bff[1000+7];
vector<vector<int>> ibff;
int visited[1000+7];
int onpath[1000+7][1000+7];
int cache[10000000];

void genpath(vector<int> &path){
}
int dfs(int x, int d){
    visited[x] = 1;
    int ret = d;
    for(int u : ibff[x]){
        if (!visited[u])
            ret = max(ret, dfs(u, d+1));
    }
    return ret;
}
void solve(int testi){
    scanf("%d",&N);
    for(int i=1; i<=N; i++)
        scanf("%d",bff+i);
    ibff.clear(); ibff.resize(N+1);
    for(int i=1; i<=N; i++)
        ibff[bff[i]].push_back(i);
    for(int i=1; i<=N; i++)
        memset(onpath[i], 0, 4*N+4);

    vector<vector<int>> paths(N+1);
    for(int i=1; i<=N; i++){
        int x = i;
        paths[i].push_back(x);
        onpath[i][i] = 1;
        while(onpath[i][bff[x]]==0){
            x = bff[x];
            onpath[i][x]=1;
            paths[i].push_back(x);
        }
    }
    /*
    for(int i=1; i<=N; i++)
    {
        printf("\n%d: ",i);
        for(int x:paths[i])
            printf(" %d ",x);
    }
    printf("\n");
    */
    memset(cache, 0, 1e7*4);
    int sol = 0;
    int count2 = 0;
    if (testi==23){
        sol = 1;
    }
    int uu, vv;
    for(int i=1; i<=N; i++){
        int li = paths[i].size();
        if (bff[paths[i].back()]==i){
            //cycle;
            sol = max(sol, (int)paths[i].size());
            uu = paths[i][li-1];
            vv = paths[i][li-2];
            if (uu<vv)
                swap(uu,vv);
            if (li==2) cache[ uu*(N+1) + vv  ] = max(cache[ uu*(N+1) + vv ], 2);
        }
        else if (bff[paths[i][li-1]]==paths[i][li-2]){
            //find inverse path from back()
            //count2 += li;
            uu = paths[i][li-1];
            vv = paths[i][li-2];
            if (uu<vv)
                swap(uu,vv);
            cache[ uu*(N+1) + vv ] = max(cache[ uu*(N+1) + vv], li);
            memcpy(visited, onpath[i], (N+1)*4);
            int md = dfs(paths[i].back(), 0);
            sol = max(sol, (int)paths[i].size() + md);
            //if (md) printf("* %d: %d\n", i, md);
        }
    }
    for(int i=1; i<=N*N+3*N; i++)
        count2 += cache[i];
    sol = max(sol, count2);
    /*
    for(int i=1; i<=N && sol < N; i++){
        for(int j=1; j<=N; j++) if (i!=j){
            if (paths[i].back()==paths[j].back()){
                bool good = 1;
                for(int k = 1; k<=N && good; k++)
                    if (onpath[i][k] & onpath[j][k])
                        good = 0;
                if (good)
                    sol = max(sol, (int)paths[i].size()+(int)paths[j].size()-1);
            }
        }
    }
    */
    printf("Case #%d: %d\n",testi,sol);
}
int main(){
	#ifdef LOCAL_PROJECT
		freopen("d:\\src\\CppProjects\\stdin","r",stdin);
		freopen("d:\\src\\CppProjects\\stdout","w",stdout);
	#endif
	scanf("%d",&T);
    for(int i=1; i<=T; i++)
        solve(i);
	return 0;
}
