#include<cstdio>

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int ii = 1; ii<= T; ++ii)
    {
        int N;
        int S[205];
        int X = 0;
        scanf("%d ",&N);

        for(int i = 0; i < N; ++i)
        {
            scanf("%d ", S+i);
            X += S[i];
        }

        double eps = 1e-10;
        printf("Case #%d:", ii);
        for(int i = 0; i < N; ++i) {
            double hi = 1;
            double lo = 0;

            while(hi > lo + eps)
            {
                double mid = (hi+lo)/2;
                double left = 1-mid;

                bool found = false;
                for(int j = 0; j < N; ++j) if(j != i)
                {
                    double cd = (S[i] - S[j] + X * mid) / X;
                    if (cd > 0)
                    {
                        if(cd <= left) left -= cd;
                        else
                        {
                    //        printf(" --%d--", j);
                            found = true;
                            break;
                        }
                    }
                }

                if(found)
                    hi = mid;
                else
                    lo = mid;
                //printf(" (%lf,%lf)", hi, lo);
            }
            printf(" %.8lf",hi*100);
        }
        printf("\n");
    }
    return 0;
}
