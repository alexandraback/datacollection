#include <stdio.h>
#include <string.h>
#include "algorithm"
#include "iostream"

using namespace std;

struct point
{
    char start, end;
} node[14];

main()
{
    //freopen("A-large.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T, i, cas=0, key, n, sum, num;
    char input[150];

    scanf("%d", &T);

    while(T--)
    {
        key=1;
        scanf("%d", &n);
        for(i=0; i<=n-1; i++)
        {
            scanf("%s", input);
            node[i].start=input[0];
            node[i].end=input[strlen(input)-1];
            if(node[i].start==node[i].end)
            {
                key==0;
            }
        }
        if(key==0)
        {
            printf("Case #%d: 0\n", ++cas);
            break;
        }
        if(n==1)
        {
            printf("Case #%d: 1\n", ++cas);
            break;
        }
        sum=0;
        do
        {
            num=0;
            for(i=0; i<=n-2; i++)
            {
                if(node[i].end==node[i+1].start)
                {
                    num++;
                }
            }
            if(num==n-1)
            {
                sum++;
            }
        }while(next_permutation(node,node+n));
        printf("Case #%d: %d\n", ++cas, sum);
    }


    return 0;
}
