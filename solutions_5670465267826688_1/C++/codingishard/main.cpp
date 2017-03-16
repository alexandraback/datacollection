//
//  main.cpp
//  Dijkstra
//
//  Created by 서승현 on 2015. 4. 11..
//  Copyright (c) 2015년 서승현. All rights reserved.
//

#include <cstdio>
#include <cstring>

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

int b;
int recur(long long k)
{
    if(k == 0) return 0;
    
    int t = recur(k >> 1);
    t = states[t][t];
    if(k & 1) t = states[t][b];
    
    return t;
}

bool solve()
{
    int L;
    long long X;
    scanf("%d %lld %s", &L, &X, str);
    
    int s = 0; long long e = L * X;
    int a = 0, c = 0;
    
    for(int i = 0, l = 0;a != 1 && l < 8;++s)
    {
        a = states[a][map[str[i++]]];
        if(i == L) i = 0, ++l;
    }
    if(a != 1) return false;
    
    for(int i = L, l = 0;c != 3 && l < 8;--e)
    {
        c = states[map[str[--i]]][c];
        if(!i) i = L, ++l;
    }
    if(c != 3 || s >= e) return false;
    
    a = 0;
    for(int i = s % L;i < L && s < e;++s) a = states[a][map[str[i++]]];
    
    c = 0;
    for(int i = e % L;i > 0 && s < e;--e) c = states[map[str[--i]]][c];
    
    b = 0;
    for(int i = 0;i < L;++i) b = states[b][map[str[i]]];
    b = recur((e - s) / L);
    // s = 2, e = 7
    // L = 4, X = 3
    // s = 4, e = 4
    // 1100/0001/1111
    
    return states[a][states[b][c]] == 2;
}

int main(int argc, const char * argv[])
{
    FILE *input = freopen("input.txt", "r", stdin);
    FILE *output = freopen("output.txt", "w", stdout);
    
    map['i'] = 1;
    map['j'] = 2;
    map['k'] = 3;
    
    int T; scanf("%d", &T);
    for(int i = 1;i <= T;++i)
        printf("Case #%d: %s\n", i, solve() ? "YES": "NO");
    
    fclose(input);
    fclose(output);
    
    return 0;
}