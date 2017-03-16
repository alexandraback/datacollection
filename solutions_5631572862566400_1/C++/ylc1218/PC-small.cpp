#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> redge[1005];
int edge[1005], isgo[1005];
int N, T;

int findMaxPath(int now, int p){
    int cnt = 0;
    for(int i=0;i<redge[now].size();i++){
        int nxt = redge[now][i];
        if(nxt == p) continue;
        cnt = max(findMaxPath(nxt, p), cnt);
    }
    return cnt+1;
}

int main(){
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        scanf("%d", &N);

        memset(edge, 0, sizeof(edge));
        for(int i=1;i<=N;i++) redge[i].clear();
        for(int i=1;i<=N;i++){
            scanf("%d", &edge[i]);
            redge[edge[i]].push_back(i);
        }

        //find largest cycle
        int maxCycle = 0;
        for(int s=1;s<=N;s++){
            memset(isgo, 0, sizeof(isgo));
            int now = s, cnt = 0;
            while(!isgo[now]){
                isgo[now] = 1;
                cnt++;
                now = edge[now];
            }
            if(now == s) maxCycle = max(maxCycle, cnt);
        }

        //find two-node cycles
        int maxCycle2 = 0;
        for(int i=1;i<=N;i++){
            int j = edge[i];
            if(i>j || edge[j] != i) continue;

            int cnt = findMaxPath(i, j)+findMaxPath(j, i);
            maxCycle2 += cnt;
        }
        printf("Case #%d: %d\n", t, max(maxCycle, maxCycle2));
    }
    return 0;
}
