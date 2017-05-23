//Google Code Jam Round 1C 2014 - Problem B.
//https://code.google.com/codejam

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

long long ans;
bool visit[11], check[500];
int N, len[11];
char s[11][101], str[10000];

bool judge(char* str)
{
    int len = strlen(str);
    //printf("%s %d\n", str, len);
    memset(check, false, sizeof(check));

    char tmp1, tmp2;
    tmp1 = str[0];
    check[tmp1] = true;

    for(int i = 1; i < len; i++)
    {
        tmp2 = str[i];
        if(tmp1 == tmp2 )
            continue;
        if(tmp1 != tmp2)
        {
            if(check[tmp2])//appear before
                return false;
            //next char
            tmp1 = tmp2;
            check[tmp2] = true;
            continue;
        }
    }
    return true;
}
void dfs(int now, int p, int index)
{

    for(int i = 0; i < len[now]; i++)
    {
        str[index] = s[now][i];
        index++;
    }
    if(p == N)
    {
        str[index] = '\0';
        if(judge(str))
        {
            //printf("%s\n", str);
            ans ++;
        }
        return;
    }

    for(int i = 0; i< N; i++)
    {
        if(!visit[i])
        {
            visit[i] = true;
            dfs(i, p+1, index);
            visit[i] = false;
        }
    }
}

int main()
{
    freopen ("b_output.txt","w",stdout);

    int T;

    scanf("%d", &T);

    for(int testCase = 1; testCase <= T; testCase++)
    {
        scanf("%d", &N);
        ans = 0;

        for(int i = 0; i < N; i++)
        {
            scanf("%s", &s[i]);
            len[i] = strlen(s[i]);
        }
        memset(visit, false, sizeof(visit));

        for(int i = 0; i < N; i++)
        {
            visit[i] = true;
            dfs(i, 1, 0);
            visit[i] = false;
        }

        printf("Case #%d: ", testCase);
        printf("%lld\n", ans);
    }
    return 0;
}
