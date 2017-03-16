#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100+5;
int T;
char line[MAXN], map[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T); gets(line);
    for (int cas = 1; cas <= T; cas++)
    {
        gets(line);
        int len = strlen(line)-1;
        printf("Case #%d: ", cas);
        for (int i = 0; i < len; i++)
        {
            if (line[i] == ' ')
                printf("%c", line[i]);
            else
                printf("%c", map[line[i]-'a']);
        }
        printf("\n");
    }
    return 0;
}
