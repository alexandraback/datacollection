#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("large.out","w",stdout);
    int T;
    char s[1005];
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++)
    {
        scanf("%s",s);
        deque<char> v;
        v.push_back(s[0]);
        for(int i=1;s[i];i++)
        {
            if(s[i]>=v[0])
                v.push_front(s[i]);
            else
                v.push_back(s[i]);
        }
        printf("Case #%d: ",cases);
        for(int i=0;i<(int)v.size();i++)
            putchar(v[i]);
        puts("");
    }
    return 0;
}
