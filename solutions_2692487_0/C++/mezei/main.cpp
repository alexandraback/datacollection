#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int T;
int A, N;
int M[110];
int operations;
int sol;
int main()
{
    FILE* reader = fopen("A.in", "r");
    FILE* printer = fopen("IA.out", "w");

    fscanf(reader, "%d", &T);

    for(int T_id=1; T_id<=T; T_id++)
    {

        fscanf(reader, "%d %d", &A, &N);
        for(int i=0; i<N; i++)
            fscanf(reader, "%d", &M[i]);

        sort(M, M+N);
        sol=N;
        operations=0;

        //printf("%d %d\n", sol, operations);
        int at=0;
        while(at<N && sol>operations)
        {

            sol=min(sol, operations+(N-at));
            if(A>M[at])
            {
                A+=M[at];
                at++;
            }
            else
            {
                A=2*A-1;
                operations++;
            }
        }

        sol=min(sol, operations);

        //printf("Case #%d: %d\n", T_id, sol);
        fprintf(printer, "Case #%d: %d\n", T_id, sol);
    }



    fclose(printer);
}
