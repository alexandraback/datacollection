//
//  main.cpp
//  Dijkstra
//
//  Created by 서승현 on 2015. 4. 11..
//  Copyright (c) 2015년 서승현. All rights reserved.
//

#include <cstdio>
#include <string>

using namespace std;

char str[10005];
char map['k' + 1];
int states[][8] = {
    0,1,2,3,4,5,6,7,
    1,4,3,6,5,0,7,2,
    2,7,4,1,6,3,0,5,
    3,2,5,4,7,6,1,0,
    4,5,6,7,0,1,2,3,
    5,0,7,2,1,4,3,6,
    6,3,0,5,2,7,4,1,
    7,6,1,0,3,2,5,4
};

int main(int argc, const char * argv[])
{
    FILE *input = freopen("input.txt", "r", stdin);
    FILE *output = freopen("output.txt", "w", stdout);
    
    map['i'] = 1;
    map['j'] = 2;
    map['k'] = 3;
    
    int T; scanf("%d", &T);
    for(int i = 1;i <= T;++i)
    {
        int L, X; scanf("%d %d %s", &L, &X, str);
        
        for(int i = 1, k = L;i < X;++i)
            for(int j = 0;j < k;++j)
                str[L++] = str[j];
        
        int s = 0, e = L;
        int a = 0, b = 0, c = 0;
        while(s < e)
        {
            if(a != 1) a = states[a][map[str[s++]]];
            if(c != 3) c = states[map[str[--e]]][c];
            if(a == 1 && c == 3) break;
        }
        
        while(s < e) b = states[b][map[str[s++]]];
        printf("Case #%d: %s\n", i, b == 2 ? "YES": "NO");
    }
    fclose(input);
    fclose(output);
    
    return 0;
}