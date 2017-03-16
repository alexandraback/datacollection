#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int TC;
int N;
int P[2001];
bool vis[2001], instack[2001];
vector<int> C[2001];
int gdepth(int id){
    int ret = 0;
    for(auto i : C[id]) if(P[id] != i) ret = max(ret, gdepth(i));
    return ret + 1;
}
int loopsize(int x){
    memset(instack, 0, sizeof(instack));
    for(int i = x; true ; i = P[i]){
        if(instack[i]){
            int j = 1;
            for(int k = P[i]; k != i; k = P[k]) ++j;
            return j;
        }
        instack[i] = true;
    }
}
int main(){
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc){
        scanf("%d", &N);
        for(int i = 1; i <= N; ++i){
            C[i].clear();
            vis[i] = false;
            instack[i] = false;
        }
        for(int i = 1; i <= N; ++i){
            scanf("%d", &P[i]);
            C[P[i]].push_back(i);
        }
        int ans = 0;
        for(int i = 1; i <= N; ++i){
            ans = max(ans, loopsize(i));
        }
        int aans = 0;
        for(int i = 1; i <= N; ++i){
            if(P[P[i]] == i && i < P[i]){
                aans += gdepth(i) + gdepth(P[i]);
            }
        }
        //printf("%d %d\n", ans, aans);
        printf("Case #%d: %d\n", tc, max(aans, ans));
    }
}
            
