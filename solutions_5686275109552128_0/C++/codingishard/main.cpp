//
//  main.cpp
//  Infinite House of Pancakes
//
//  Created by 서승현 on 2015. 4. 11..
//  Copyright (c) 2015년 서승현. All rights reserved.
//

#include <cstdio>

int main(int argc, const char * argv[])
{
    FILE *input = freopen("input.txt", "r", stdin);
    FILE *output = freopen("output.txt", "w", stdout);
    
    int T; scanf("%d", &T);
    for(int i = 1;i <= T;++i)
    {
        int D, ans = 0;
        int cnt[1001] = {0};
        
        for(scanf("%d", &D);D--;)
        {
            int P; scanf("%d", &P);
            ++cnt[P];
            
            if(ans < P) ans = P;
        }
        
        for(int i = ans, j = 0;i > 1;--i)
        {
            if(cnt[i])
            {
                if(ans > i + j) ans = i + j;
                
                j += cnt[i];
                cnt[i / 2] += cnt[i];
                cnt[(i + 1) / 2] += cnt[i];
            }
        }
        printf("Case #%d: %d\n", i, ans);
    }
    fclose(input);
    fclose(output);
    
    return 0;
}