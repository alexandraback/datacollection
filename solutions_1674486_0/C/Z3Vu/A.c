#include<stdio.h>
int main()
{
    char E[1000][1001]; // edge
    char V[1000][1001]; // visit
    char C[1000][1001]; // current
    char D[1000][1001]; // after-current
    long T,tc,N,I,J,K,a,b;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&T);
    for(tc=1;tc<=T;tc++)
    {
        scanf("%ld",&N);
        for(I=0;I<N;I++)
            for(J=0;J<N+1;J++)
                E[I][J] = V[I][J] = C[I][J] = D[I][J] = 0;
        for(I=0;I<N;I++)
        {
            V[I][I] = 1;
            D[I][0] = 1;
            D[I][1] = I;
        }
        for(I=0;I<N;I++)
        {
            scanf("%ld",&E[I][0]);
            for(J=1;J<=E[I][0];J++)
            {
                scanf("%ld",&E[I][J]);
                E[I][J]--;
            }
        }
        while(1)
        {
            for(I=0;I<N;I++)
                for(J=0;J<=N;J++)
                {
                    C[I][J] = D[I][J];
                    D[I][J] = 0;
                }
            for(I=0;I<N;I++)
                if(C[I][0] != 0)
                    break;
            if(I == N)
                break;
            for(I=0;I<N;I++)
            {
                for(J=1;J<=E[I][0];J++)
                {
                    for(K=1;K<=C[I][0];K++)
                    {
                        if(V[E[I][J]][C[I][K]] == 1)
                        {
                            I = J = K = N+1;
                            break;
                        }
                        V[E[I][J]][C[I][K]] = 1;
                        D[E[I][J]][0]++;
                        D[E[I][J]][D[E[I][J]][0]] = C[I][K];
                    }
                    if(I == N+1)
                        break;
                }
                if(I == N+1)
                    break;
            }
            if(I == N+1)
                break;

        /*for(a=0;a<N;a++)
        {
            for(b=0;b<N;b++)
                printf("%ld ",V[a][b]);
            printf("\n");
        }
        printf("\n");*/
        }
        if(I == N+1)
            printf("Case #%ld: Yes\n",tc);
        else
            printf("Case #%ld: No\n",tc);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
