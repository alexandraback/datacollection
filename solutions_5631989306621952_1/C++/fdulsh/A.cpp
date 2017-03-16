#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=1010;

int n;
char s[maxn];

struct Str
{
       char c; int x;
       bool operator <(const Str &rhs)const
       {
            return x<rhs.x;
       }
}S[maxn];

void init()
{
     scanf("%s",s+1);
     n=strlen(s+1);
     for(int i=1;i<=n;i++) S[i].c=s[i],S[i].x=0;
}

void work()
{
     int l=1,r=1;
     S[1].x=0;
     for(int i=2;i<=n;i++)
         if(S[i].c>=S[l].c) S[i].x=S[l].x-1,l=i;
            else S[i].x=S[r].x+1,r=i;
     sort(S+1,S+n+1);
     for(int i=1;i<=n;i++) printf("%c",S[i].c);
     printf("\n");
}

int main()
{
    int TT;
    scanf("%d",&TT);
    for(int i=1;i<=TT;i++)
    {
        printf("Case #%d: ",i);
        init();
        work();
    }
    return 0;
}
