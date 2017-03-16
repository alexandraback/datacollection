//
//  main.cpp
//  Counter Culture
//
//  Created by 서승현 on 2015. 5. 3..
//  Copyright (c) 2015년 서승현. All rights reserved.
//

#include <iostream>

int q[1000005][2], f, r;
bool check[1000005];

int main(int argc, const char * argv[])
{
    FILE *input = freopen("A-small-attempt0.in", "r", stdin);
    FILE *output = freopen("output.txt", "w", stdout);
    
    int T; scanf("%d", &T);
    
    for(int i = 1;i <= T;++i)
    {
        int N; scanf("%d", &N);
        
        memset(check, false, sizeof check);
        
        f = -1, r = 0;
        q[0][0] = 1;
        q[0][1] = 1;
        
        while(f < r)
        {
            int v = q[++f][0];
            int d = q[f][1];
            
            if(v == N)
            {
                printf("Case #%d: %d\n", i, d);
                break;
            }
            
            ++d;
            if(!check[v + 1])
            {
                check[v + 1] = true;
                q[++r][0] = v + 1;
                q[r][1] = d;
            }
            
            int u = v, w = 0;
            while(u)
            {
                w *= 10;
                w += u % 10;
                u /= 10;
            }
            
            if(w > N || check[w]) continue;
            
            check[w] = true;
            q[++r][0] = w;
            q[r][1] = d;
        }
    }
    
    return 0;
}