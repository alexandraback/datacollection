# include <stdio.h>


int main(void)
{
    //var 
    int t,a, b;
    int temp,temp1,temp2;

    unsigned long long r,s,n,ar,ar2,gap;

    //loop
    int i,j,k,l,flag;


    scanf("%d ",&t);

    for(i=0;i<t;i++)
    {
        scanf("%llu ",&r);
        scanf("%llu ",&s);

        flag = 0;
        n = 1;
        gap = 1;

        // Solve
        do
        {
//            printf("-%llu-\n",n);
            ar =  2*n*n + 2*n*r - n;

            if(ar < s)
            {
                gap = 2*gap;
                n = n + gap;
            }
            else if (ar > s)
            {
                n = n - gap;
                gap = gap/2;
                if (gap == 0)
                {  // printf("Oin\n");
                    break; }
                n = n + gap;
            }
            else if (ar == s)
                break;
            

            if (gap == 1)
            {
            //    printf("In \n");
                ar2 =  2*n*n + 2*n*r - n;
                if ((ar <  s) && (s < ar2))
                {
              //      printf("In2 \n");
                    break;
                }
            }
        }
        while(1);

        // output print
        printf("Case #%d: %llu\n",i+1,n);
     }

    return 1;
}

