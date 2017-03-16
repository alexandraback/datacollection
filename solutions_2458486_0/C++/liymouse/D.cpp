#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

typedef struct
{
    int need , num;
    int get[30];
}Chest;
int n;
int key[210];
Chest chest[30];
int open[30];
int path[30];
int ans;
set<int> hash;

void dfs(int c , int num , int state)
{
    if (hash.find(state) != hash.end()) return;
    path[num] = c+1;
    open[c] = 1;
    key[chest[c].need] --;
    for (int i = 0; i < chest[c].num; i ++)
        key[chest[c].get[i]] ++;
    if (num == n-1)
    {
        ans = 1;
        return;
    }
    for (int i = 0; i < n; i ++)
        if (!open[i] && key[chest[i].need] > 0)
        {
            dfs(i , num+1 , state | (1 << i));
            if (ans) return;
        }
    hash.insert(state);
    open[c] = 0;
    key[chest[c].need] ++;
    for (int i = 0; i < chest[c].num; i ++)
        key[chest[c].get[i]] --;
}

int main()
{
	freopen("D-small-attempt2.in" , "r" , stdin);
	freopen("D-small-attempt2.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int k;
        scanf("%d %d" , &k , &n);
        memset(key , 0 , sizeof(key));
        for (int i = 0; i < k; i ++)
        {
            int x;
            scanf("%d" , &x);
            key[x] ++;
        }
        for (int i = 0; i < n; i ++)
        {
            scanf("%d %d" , &chest[i].need , &chest[i].num);
            for (int j = 0; j < chest[i].num; j ++)
                scanf("%d" , &chest[i].get[j]);
        }
        ans = 0;
        memset(open , 0 , sizeof(open));
        hash.clear();
        for (int i = 0; i < n; i ++)
        {
            if (key[chest[i].need] > 0)
            {
                dfs(i , 0 , 1<<i);
            }
            if (ans) break;
        }
        if (ans)
        {
            printf("%d" , path[0]);
            for (int i = 1; i < n; i ++) printf(" %d" , path[i]);
            printf("\n");
        }
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}