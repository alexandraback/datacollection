#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <string>
#include <cstring>

using namespace std;

int D[1<<20][40];
vector<int> way[1<<20];
bool was[1<<20];
int chest[20];
vector<int> keysInChest[20];
int maxKey = 0;

map<int,int> keys;
int transform(int k){
    if(keys.count(k) == 0){
        keys.insert(make_pair(k,maxKey));
        maxKey++;
    }
    return keys[k];
}

int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int z = 0; z < T; z++){
        memset(D,0,sizeof(D));
        memset(chest, 0, sizeof(chest));
        memset(was, -1,sizeof(was));
        for(int i = 0; i < (1<<20); i++)
            way[i].clear();
        for(int i = 0; i < 20; i++)
            keysInChest[i].clear();
        maxKey = 0;
        keys.clear();


        int K,N;
        scanf("%d%d",&K,&N);
        for(int i = 0; i < K; i++){
            int k;
            scanf("%d",&k);
            D[0][transform(k)]++;
            was[0] = true;
        }
        for(int i = 0; i < N; i++){
            int k;
            scanf("%d",&k);
            chest[i] = transform(k);
            scanf("%d",&k);
            for(int j = 0; j < k; j++){
                int k1;
                scanf("%d",&k1);
                keysInChest[i].push_back(transform(k1));
            }
        }

        for(int i = 1; i < (1<<N); i++){
            for(int j = 0; j < maxKey; j++)
                D[i][j] = D[0][j];
            for(int j = 0; j < N; j++){
                if((i & (1<<j)) != 0){
                    for(int k = 0; k < keysInChest[j].size(); k++)
                        D[i][keysInChest[j][k]]++;
                    D[i][chest[j]]--;
                }
            }
        }

        for(int i = 0; i < (1<<N); i++){
            if(!was[i])
                continue;
            for(int j = 0; j < N; j++)
                if(((i & (1<<j)) == 0 )&& (D[i][chest[j]] > 0)){
                    bool flag = false;
                    int newState = i | (1<<j);

                    if(!was[newState]){
                        was[newState] = true;
                        flag = true;
                    }

                    else{
                        for(int k = 0; k < way[i].size(); k++)
                            if(way[i][k] != way[newState][k])
                            {
                                flag = (way[i][k] < way[newState][k]);
                                break;
                            }
                    }
                    if(flag){
                        way[newState] = way[i];
                        way[newState].push_back(j);
                    }
                }
        }

        printf("Case #%d: ",z+1);
        if(!was[(1<<N) - 1])
            printf("IMPOSSIBLE");
        else
            for(int i = 0; i < N; i++)
                printf("%d ",way[(1<<N) - 1][i] + 1);

        printf("\n");
    }
    return 0;
}

