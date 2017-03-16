#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cctype>
#include <cstring>
#include <string>
#include <numeric>
#include <functional>
#include <iomanip>
#include <ctime>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;

char s[]={"ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv"};
char d[]={"our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up"};
char mp[27];
bool vis[27];
char G[105];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int n=strlen(s);
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        char c=s[i]-'a';
        if(s[i]==' ')continue;
        if(!vis[c])
        {
            mp[c]=d[i];
            vis[c]=true;
        }
    }
    mp['q'-'a']='z';
    mp['z'-'a']='q';
    /*
    for(int i=0;i<26;i++)
    {
        printf("%c->%c\n",i+'a',mp[i]);
    }
    */

    int T;
    scanf("%d",&T);
    getchar();
    for(int t=1;t<=T;t++)
    {
        gets(G);
        printf("Case #%d: ",t);
        n=strlen(G);
        for(int i=0;i<n;i++)
        {
            if(G[i]==' ')
            {
                printf(" ");
                continue;
            }
            printf("%c",mp[G[i]-'a']);
        }
        puts("");
    }
	return 0;
}
