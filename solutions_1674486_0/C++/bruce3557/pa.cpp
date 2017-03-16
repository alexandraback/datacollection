//
//  pa.cpp
//  
//
//  Created by mac on 12/5/6.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <vector>

using std::vector;
vector<int> e[1010];
int deg[1010];
int way[1010][1010];
int n;
vector<int> fp;

int main() {
    int t, cases=0;
    
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;++i) {
            e[i].clear();
            deg[i] = 0;
        }
        memset(way, 0, sizeof(way));
        for(int i=1;i<=n;++i) {
            int x;
            scanf("%d",&x);
            for(int j=0;j<x;++j) {
                int v;
                scanf("%d",&v);
                e[i].push_back(v);
                ++deg[v];
                way[i][v] = 1;
            }
        }
        
        bool ans=false;
        for(int k=1;!ans && k<=n;++k)
            for(int i=1;!ans && i<=n;++i)
                for(int j=1;!ans && j<=n;++j) {
                    if(way[i][j] > 1) {
                        ans = true;
                        break;
                    }
                    if(way[i][k] && way[k][j])
                        way[i][j] += way[i][k]&way[k][j];
                }

        for(int i=1;!ans && i<=n;++i)
            for(int j=1;!ans && j<=n;++j)
                if( way[i][j] > 1 ) 
                    ans = true;
        
        if(ans) printf("Case #%d: Yes\n", ++cases);
        else    printf("Case #%d: No\n", ++cases);
    }
    
    return 0;
}