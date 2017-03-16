//
//  main.cpp
//  Ominous Omino
//
//  Created by 서승현 on 2015. 4. 11..
//  Copyright (c) 2015년 서승현. All rights reserved.
//

#include <cstdio>
#include <algorithm>

int main(int argc, const char * argv[])
{
    FILE *input = freopen("input.txt", "r", stdin);
    FILE *output = freopen("output.txt", "w", stdout);
    
    int T; scanf("%d", &T);
    for(int i = 1;i <= T;++i)
    {
        int X, R, C; scanf("%d %d %d", &X, &R, &C);
        if(R > C) std::swap(R, C);
        
        bool Richard = false;
        if(X == 2) Richard = (R * C) & 1;
        else if(X == 3) Richard = (R != 2 || C != 3) && (R != 3 || (C != 3 && C != 4));
        else if(X == 4) Richard = (R != 3 && R != 4) || C != 4;
        
        printf("Case #%d: %s\n", i, Richard ? "RICHARD" : "GABRIEL");
    }
    
    fclose(input);
    fclose(output);
    
    return 0;
}