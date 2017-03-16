//
//  main.cpp
//  codejam
//
//  Created by Cloudzfy on 3/11/15.
//  Copyright (c) 2015 Cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MIN(a,b) (a)<(b)?(a):(b)
#define eps 1e-15
int ans;
void dfs(vector<vector<bool> >& map, vector<bool>& visited, vector<int>& F, vector<bool>& bbf, int cur, int N, int depth, int start) {
    visited[cur] = true;
    if (bbf[cur] || F[cur] == start) {
        ans = max(ans, depth);
    }
    if (bbf[cur]) {
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            if (!map[cur][i]) continue;
            if (F[i] == cur) bbf[i] = true;
            dfs(map, visited, F, bbf, i, N, depth + 1, start);
            if (F[i] == cur) bbf[i] = false;
        }
    } else {
        if (F[F[cur]] == cur) bbf[F[cur]] = true;
        if (!visited[F[cur]]) dfs(map, visited, F, bbf, F[cur], N, depth + 1, start);
        if (F[F[cur]] == cur) bbf[F[cur]] = false;
    }
    visited[cur] = false;
}
int main(int argc, const char * argv[]) {
    int T,N;
    freopen("C-small-attempt0.in.txt","r",stdin);
    freopen("C-small-attempt0.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d", &N);
        ans = 0;
        vector<int> F(N, 0);
        vector<vector<bool> > map(N, vector<bool>(N, false));
        vector<bool> visited(N, false);
        vector<bool> bbf(N, false);
        for (int i = 0; i < N; i++) {
            scanf("%d",&F[i]);
            F[i]--;
        }
        for (int i = 0; i < N; i++) {
            map[i][F[i]] = true;
            map[F[i]][i] = true;
        }
        for (int i = 0; i < N; i++) {
            dfs(map, visited, F, bbf, i, N, 1, i);
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
