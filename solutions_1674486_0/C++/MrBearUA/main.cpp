//
//  main.cpp
//  codejam_1cr_a
//
//  Created by Andriy Medvid' on 06.05.12.
//  Copyright (c) 2012 taran studio. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

int main(int argc, const char * argv[])
{
    int T;
    int n;
    freopen("a.out", "w", stdout);
    freopen("A-small-attempt0.in", "r", stdin);
    scanf("%d", &T);
    
    for(int t = 0; t < T; t++)
    {
        std::vector<int> lines[1000];
        int visits[1000];
        
        bool theDouble = false;
        
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            int m, a;
            scanf("%d", &m);
            for(int j = 0; j < m; j++)
            {
                scanf("%d", &a);
                lines[i].push_back(a-1);
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                visits[j] = 0;
            }
            std::stack<int> next;
            next.push(i);
            while (!next.empty())
            {
                int val = next.top();
                visits[val]++;
                next.pop();
                for(int j = 0; j < lines[val].size(); j++)
                {
                    next.push(lines[val][j]);
                }
            }
            
            for(int j = 0; j < n; j++)
                if(visits[j] > 1)
                    theDouble = true;
        }
        if(theDouble)
            printf("Case #%d: Yes\n", t+1);
        else
        {
            printf("Case #%d: No\n", t+1);
        }
        
    }
    
    return 0;
}