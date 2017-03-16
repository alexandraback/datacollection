#include <cstdio>


using namespace std;
typedef unsigned long long int lld;


int E,R,N;
int vi[10000];

lld solve()
{
    lld sum= 0;
    lld rest = E;
    for(int i=0; i < N; i++)
    {

        lld now = vi[i];
        lld j=i;
        lld r=0;
        for( ;j < N && r <= E && vi[j]<=now ;j++,r+=R);
        if(j<N && r < E&& vi[j] > now ) // handle
        {
           // printf("next peak = %d\n",vi[j]);
            lld canrest = E - (j-i)*R;
           // printf("can = %d\n",canrest);
            if( canrest <= rest)
            {
                sum += now * (rest - canrest);
                rest = canrest;
            }
        }
        else //spend all
        {
            sum += now * rest;
            rest = 0;
        }
        rest += R;
        if(rest >E)rest =E;
    }
    return sum;
}


int main()
{
    int T, cases = 0;
    scanf("%d", &T);
    while(T--)
    {


        scanf("%d%d%d",&E,&R,&N);
        for(int i =0 ; i<N;i++)
        {
            scanf("%d",&vi[i]);
        }
        lld out = solve();
        printf("Case #%d: %lld\n",++cases, out);
    }


    return 0;
}
