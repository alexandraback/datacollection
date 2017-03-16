#include<iostream>
#include<cstdio>
#include <cstring>

using namespace std;

char s[10100];

int findMax(char* s, const int &len)
{

}

char st[100000];
bool mark[100000];

int main()
{
    freopen("d:\\A-large.in", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
    int oo;
    scanf("%d", &oo);
    for(int o = 0; o < oo; o++)
    {
        memset(mark, false, sizeof(mark));
        scanf("%s", &s);
        int len = strlen(s);
        int tt = -1;
        for(int i = 0; i < len; i++)
            if (tt == -1 || st[tt] <= s[i])
            {
                tt++;
                st[tt] = s[i];
                mark[i] = true;
            }
        printf("Case #%d: ", o+1);
        for(int i = len - 1; i >= 0; i--)
            if(mark[i])
                printf("%c", s[i]);
        for(int i = 0; i < len; i++)
            if(!mark[i])
                printf("%c", s[i]);
        printf("\n");
    }
}
