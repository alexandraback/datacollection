#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt","r+",stdin);
    freopen("output.txt","w+",stdout);

    int T;
    scanf("%d",&T);

    int s,n,detd,dete,buf,e;
    int chast[100];

    for(int t=0;t<T;t++)
    {
        s=0;n=0;detd=0;dete=0;
        scanf("%d %d",&s,&n);
        for(int i=0; i<n;i++)
            scanf("%d",&chast[i]);
        sort(chast,chast+n);
        if(s==1)
        {
            printf("Case #%d: %d\n",t+1,n);
            continue;
        }

        for(e=0;e<n;e++)
        {
            if(chast[e]<s)
                s+=chast[e];
            else
            {
                if((detd==0)||(detd>dete+n-e))
                    detd=n-e+dete;
                while(s<= chast[e])
                {
                    s+=s-1;
                    dete++;
                }
                s+=chast[e];

            }
            if(s>100)
             break;
        }
        printf("Case #%d: %d\n",t+1,min(detd,dete));
    }

    return 0;
}
