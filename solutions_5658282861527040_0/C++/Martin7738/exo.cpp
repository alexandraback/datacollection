#include <cstdlib>
#include <cstdio>

using namespace std;
    
void resp (int curCase)
{
	int A, B, K;
    scanf("%d%d%d", &A, &B, &K);
    int nbComb = 0;
    for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++)
            if ((i&j) < K)
            {
            	//printf("A : %d - B : %d, A&B : %d\n", i, j, i&j);
                nbComb++;
            }

    printf ("Case #%d: %d\n", curCase, nbComb);
}

int main ()
{
	int nbCase;
	scanf("%d", &nbCase);
	
	for (int i = 1; i <= nbCase; i++)
		resp(i);

    return 0;
}
