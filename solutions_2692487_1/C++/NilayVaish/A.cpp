#include<cstdio>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
    int T;
    scanf("%d\n", &T);

    for(int ii = 1; ii <= T; ++ii)
    {
        unsigned int A, N;
        unsigned int M[105];
        scanf("%d %d\n", &A, &N);
        for(int i = 0 ; i < N; ++i) scanf("%d", M+i);
        sort(M, M+N);

        unsigned int S = 0;
        unsigned int SS = N;
        for(int i = 0 ; i < N; ++i)
        {
            if (M[i] < A) A += M[i];
            else
            {
                int T = 0;
                // Create new motes
                while(A <= M[i] && T < (N-i))
                {
                    A += (A-1);
                    T++;
                }
                A += M[i];
                if (T >= N-i) {
                    S += (N-i);
                    break;
                }
                else {
                    SS = min(SS, S + N-i);
                    S += T;
                }
            }
        }
        printf("Case #%d: %d\n", ii, min(SS,S));
    }
    return 0;
}
