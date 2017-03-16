#include <stdio.h>
using namespace std;
int t,n,contor,suma;
char x;
int main()
{
    freopen("text.in","r",stdin);
    freopen("text.out","w",stdout);
    scanf("%d ",&t);
    for(int k=1;k<=t;++k)
    {
        printf("Case #%d: ",k);
        scanf("%d ",&n);
        suma = 0;
        scanf("%c",&x);
        contor = x-'0';
        for(int i=1;i<=n;++i)
        {
            scanf("%c",&x);
            if(x>'0')
            {
                if(contor<i)
                {
                    suma = suma+i-contor;
                    contor = i+x-'0';
                }
                else contor = contor+x-'0';
            }
        }
        scanf("%c",&x);
        printf("%d\n",suma);
    }
    return 0;
}
