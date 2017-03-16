#include<cstdio>

int main()
{
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; ++i)
    {
        int J, P, S, K;
        int day = 0;
        int JP[10+1][10+1], PS[10+1][10+1], JS[10+1][10+1];
        bool JPS[10+1][10+1][10+1];
        for(int j=0; j<11; ++j)
        {
            for(int k=0; k<11; ++k)
            {
                JP[j][k] = 0;
                PS[j][k] = 0;
                JS[j][k] = 0;
                for(int l=0; l<11; ++l) JPS[j][k][l] = false;
            }
        }
        scanf("%d", &J);
        scanf("%d", &P);
        scanf("%d", &S);
        scanf("%d", &K);
            for(int s=0; s<S; ++s)
            {
                for(int p=0; p<P; ++p)
                {
                    for(int j=0; j<J; ++j)
                    {
                        if(JPS[j][p][s] || JP[j][p]==K || PS[p][s]==K || JS[j][s]==K) continue;
                        else
                        {
                            day++;
                            JPS[j][p][s] = true;
                            JP[j][p]++;
                            PS[p][s]++;
                            JS[j][s]++;
                        }
                    }
                }
            }
        printf("Case #%d: %d\n", i+1, day);
        for(int j=0; j<J; ++j) for(int p=0; p<P; ++p) for(int s=0; s<S; ++s) if(JPS[j][p][s]) printf("%d %d %d\n", j+1, p+1, s+1);
    }
    return 0;
}
