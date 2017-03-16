#include <stdio.h>

main()
{
    freopen("C-small-1-attempt1.in","r",stdin);
    freopen("luckyout.txt","w",stdout);
    int r,n,m,k;
    scanf("%d",&r);
    printf("Case #1:\n");
    scanf("%d%d%d%d",&r,&n,&m,&k);
    int num,i,twocount=0,threecount=0,two=0,three=0,fivecount=0,five=0,four=0;
    for (m=0;m<r;m++)
    {
        for (i=0;i<k;i++)
        {
            scanf("%d",&num);
            while (num%2 == 0)
            {
                num /= 2;
                twocount++;
            }
            while (num%3 == 0)
            {
                num /= 3;
                threecount++;
            }
            while (num%5 == 0)
            {
                num /= 5;
                fivecount++;
            }
            if (twocount > two) two = twocount;
            if (threecount > three) three = threecount;
            if (fivecount > five) five = fivecount;
            twocount = 0;
            threecount = 0;
            fivecount=0;
        }
        while (two+three+five+four > n)
        {
            if (two >= 1)
            {
                two -= 2;
                four += 1;
            }
        }
        for (i=0;i<two;i++) printf("2");
        for (i=0;i<three;i++) printf("3");
        for (i=0;i<four;i++) printf("4");
        for (i=0;i<five;i++) printf("5");
        for (i=0;i<(n-two-three-four-five);i++) printf("2");
        printf("\n");
        two = 0;
        three = 0;
        four = 0;
        five = 0;
    }

}
