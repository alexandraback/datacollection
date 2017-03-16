#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#define mem(a) memset( a, 0, sizeof(a) )
using namespace std;
typedef __int64 ll;


char s[3005];
int vis[1000], num[15];

int main()
{
    int T, i, j, n, m, cas = 1;
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while( T -- ){
        mem(vis);
        mem(num);
        scanf("%s", s);
        int n = strlen(s);
        for( i = 0; i < n; i ++ ){
            vis[s[i]] ++;
        }
        num[0] += vis['Z'];vis['E'] -= vis['Z'];vis['R'] -= vis['Z'];vis['O'] -= vis['Z'];vis['Z'] = 0;
        num[6] += vis['X'];vis['S'] -= vis['X'];vis['I'] -= vis['X'];vis['X'] = 0;
        num[8] += vis['G'];vis['E'] -= vis['G'];vis['I'] -= vis['G'];vis['H'] -= vis['G'];vis['T'] -= vis['G'];vis['G'] = 0;
        num[3] += vis['H'];vis['T'] -= vis['H'];vis['R'] -= vis['H'];vis['E'] -= vis['H']*2;vis['H'] = 0;
        num[2] += vis['T'];vis['W'] -= vis['T'];vis['O'] -= vis['T'];vis['T'] = 0;
        num[4] += vis['U'];vis['F'] -= vis['U'];vis['O'] -= vis['U'];vis['R'] -= vis['U'];vis['U'] = 0;
        num[5] += vis['F'];vis['I'] -= vis['F'];vis['V'] -= vis['F'];vis['E'] -= vis['F'];vis['F'] = 0;
        num[1] += vis['O'];vis['N'] -= vis['O'];vis['E'] -= vis['O'];vis['O'] = 0;
        num[7] += vis['S'];vis['E'] -= vis['S']*2;vis['V'] -= vis['S'];vis['N'] -= vis['S'];vis['S'] = 0;
        num[9] += vis['I'];vis['N'] -= vis['I']*2;vis['E'] -= vis['I'];vis['I'] = 0;
        printf("Case #%d: ", cas++);
        for( i = 0; i < 10; i ++ )
            for( j = 0; j < num[i]; j ++ )
            printf("%d", i);
        puts("");
    }
}
