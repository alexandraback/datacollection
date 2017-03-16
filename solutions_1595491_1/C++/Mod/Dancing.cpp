#include<stdio.h>
#include<string.h>
int t[105];
int pass,spac;

main()
{

    freopen("/Users/thanardkurutach/Desktop/C++/CodeJam/B-large.in","r",stdin);
    freopen("/Users/thanardkurutach/Desktop/C++/CodeJam/B-large.out","w",stdout);

    int T,N,S,p,least;
    scanf("%d",&T);

    for(int i=0;i<T;i++)
    {
        scanf("%d %d %d",&N,&S,&p);
        least=3*p-2;
        pass=0;
        spac=0;
        for(int j=0;j<N;j++)
        {
            scanf("%d",&t[i]);
            if(least<=t[i])
            {
                pass++;
            }
            else if(least-2<=t[i]&&(p!=1||t[i]!=0))
            {
                spac++;
            }
        }
            printf("Case #%d: ",i+1);
            if(spac>S)
            {
                printf("%d\n",S+pass);
            }
            else
            {
                printf("%d\n",spac+pass);
            }


    }
}
