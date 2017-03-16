#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>

#define readFile

using namespace std;

const int MAX = 1000010;

typedef long long LL;

int N;
char c[MAX];
int cnt[MAX];

bool consonant(char c)
{
    if(c == 'a' ||
       c == 'e' ||
       c == 'i' ||
       c == 'o' ||
       c == 'u')
    return false;
    else return true;
}

LL doit()
{
    int len = strlen(c);
    int i,j;
    LL res=0;
    int pre = -1;
    for(i=0;i<len;i++)
    {
        if(consonant(c[i]) == true)
        {
            cnt[i] = 1;
            if(i-1 >= 0) cnt[i] += cnt[i-1];
            if(cnt[i]>=N)
            {
                pre = i-N+1;
            }
        }
        else
        {
            cnt[i] = 0;
        }
        if(pre != -1)
        {
            res += pre + 1;
        }
    }
    return res;
}

int main()
{
    #ifdef readFile
        freopen("A-small-attempt0.in","r",stdin);
        freopen("A-small-attempt0.out", "w", stdout);
    #endif
    int T,cas;
    scanf("%d",&T);
    for(cas = 1;cas <= T;cas++)
    {
        scanf("%s%d", c, &N);
        printf("Case #%d: ",cas);
        cout<<doit()<<endl;
    }
    return 0;
}
