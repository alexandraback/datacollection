#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 1000000
using namespace std;

char inp[maxn];

char ca[26][3]= {"ay","bh","ce","ds","eo","fc","gv","hx","id","ju","ki","lg","ml","nb","ok","pr","qz","rt","sn","tw","uj","vp","wf","xm","ya","zq"};

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int cas,icas;
    scanf("%d",&cas);
    getchar();
    for(icas=1; icas<=cas; ++icas)
    {
        gets(inp);
        int len=strlen(inp),i;
        for(i=0; i<len; ++i)
        {
            if(inp[i] != ' ')
            {
                inp[i]=ca[inp[i]-'a'][1];
            }
        }
        printf("Case #%d: %s\n",icas,inp);
    }
    return 0;
}
