#include<stdio.h>
#include<stdio.h>

int main()
{
	int T, A, B, K, t, i, total, j;
    freopen("F:\input.txt","r", stdin);
    freopen("F:\output.txt", "w", stdout);


    scanf("%d", &T);
	for(t=1; t<=T; ++t)
	{
		scanf("%d%d%d", &A, &B, &K);
        total = 0;
		for(i=0; i<A; ++i)
        {
            for(j=0; j<B; ++j)
            {
                if((i&j)< K)
                {
                    total++;
                }

            }

        }
        printf("Case #%d: %d\n", t, total);

	}

	return 0;
}
