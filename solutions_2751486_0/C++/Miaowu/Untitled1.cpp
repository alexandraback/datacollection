#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char str[105];

bool Check(char ch)
{
    if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return false;
    return true;
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int i,j,n,cnt,ccc=1,ok,tmp,p,T,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        scanf("%d",&p);
        n=strlen(str);
        cnt=0;
        for (i=0;i<n;i++)
        {
            for (j=i+p-1;j<n;j++)
            {
                tmp=0;
                ok=0;
                for (k=i;k<=j;k++)
                {
                    if (Check(str[k]))
                    {
                        tmp++;
                        if (tmp>=p)
                        {
                            ok=1;
                            break;
                        }
                    }
                    else tmp=0;
                }
                if (ok==1)
                {
                    cnt++;
                  //  printf("%d %d\n",i,j);
                }
            }
        }
        printf("Case #%d: %d\n",ccc++,cnt);
    }
    return 0;
}
