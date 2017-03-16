#include <cstdio>

using namespace std;

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        int k,c,s;
        scanf("%d%d%d",&k,&c,&s);
        printf("Case #%d: ",t);
        for(int i=1;i<=k;i++) printf("%d ",i);
        printf("\n");
    }
    return 0;
}
