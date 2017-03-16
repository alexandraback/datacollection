#include <stdio.h>
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
    int T,t,N;
    scanf("%d", &T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&N);
        printf("Case #%d: ",t);
        if( N == 0 ) printf("INSOMNIA\n");
        else
        {
            int C, r;
            C = 0; r = 0;
            while(C<(1<<10)-1)
            {
                int temp = N * (++r);
                while(temp > 0)
                {
                    C |= 1<<(temp%10);
                    temp/=10;
                }
            }
            printf("%d\n", N*r);
        }
    }
    return 0;
}