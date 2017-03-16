#include <cstdio>

using namespace std;

char vaz[15];

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        int n;
        scanf("%d",&n);
        if(n==0) printf("Case #%d: INSOMNIA\n",t);
        else
        {
            for(int i=0;i<=9;i++) vaz[i]=0;
            for(int i=1;;i++)
            {
                for(int x=i*n;x;x/=10) vaz[x%10]=1;
                int ok=1;
                for(int i=0;i<=9;i++)
                    if(!vaz[i]) ok=0;
                if(ok)
                {
                    printf("Case #%d: %d\n",t,i*n);
                    break;
                }
            }
        }
    }
    return 0;
}
