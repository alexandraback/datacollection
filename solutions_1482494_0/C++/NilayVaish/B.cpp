#include<cstdio>
#include<cstring>

int main()
{
    int T;
    scanf("%d\n",&T);

    for(int ii = 1; ii <= T; ++ii)
    {
        int N;
        int A[1005], B[1005];
        int C[1005];

        memset(C,0,sizeof(C));
        scanf("%d\n", &N);

        for(int i = 0; i < N; ++i) scanf("%d %d\n", A+i, B+i);

        int cc = 0;
        int mx = 0;

        int qw = 0;
        while(qw != N)
        {
            bool found = false;
            for (int i = 0; i < N; ++i) if(C[i] != 2 && mx >= B[i])
            {
                if (C[i] == 1)
                {
                    mx++;
                    C[i] = 2;
                    cc++;
                    found = true;
                    qw++;
                }

                else if(C[i] == 0)
                {
                    cc++;
                    mx+= 2;
                    C[i] = 2;
                    found = true;
                    qw++;
                }
            }

            if(!found)
            {
                for (int i = 0; i < N; ++i) if(C[i] == 0 && mx >= A[i])
                {
                    cc++;
                    mx++;
                    C[i] = 1;
                    found = true;
                    break;
                }
            }

            if(!found) break;
        }

        if(qw == N) printf("Case #%d: %d\n", ii, cc);
        else printf("Case #%d: Too Bad\n",ii);
    }

    return 0;
}
