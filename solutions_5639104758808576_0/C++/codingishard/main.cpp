//
//  main.cpp
//  Standing Ovation
//
//  Created by 서승현 on 2015. 4. 11..
//  Copyright (c) 2015년 서승현. All rights reserved.
//

#include <cstdio>

char digits[1005];

int main(int argc, const char * argv[])
{
    FILE *input = freopen("input.txt", "r", stdin);
    FILE *output = freopen("output.txt", "w", stdout);
    
    int T; scanf("%d", &T);
    for(int i = 1;i <= T;++i)
    {
        int S; scanf("%d %s", &S, digits);
        
        int s = digits[0] ^ 0x30, ans = 0;
        for(int i = 1;i <= S;++i)
        {
            if(i > s)
            {
                ans += i - s;
                s = i;
            }
            
            s += digits[i] ^ 0x30;
        }
        printf("Case #%d: %d\n", i, ans);
    }
    fclose(input);
    
    return 0;
}