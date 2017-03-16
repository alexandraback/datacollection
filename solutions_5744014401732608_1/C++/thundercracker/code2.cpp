#include <bits/stdc++.h>
using namespace std;

int X[55][55];

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B_out2.txt", "w", stdout);

    int T;
    cin >> T;

    for(int test=1; test<=T; test++)
    {
        int N;
        long long B;
        cin >> N >> B;

        long long ans = 1;

        for(int i=1; i<=N-2; i++)
            ans = ans*2;

        printf("Case #%d: ", test);

        if(B>ans)
            cout << "IMPOSSIBLE\n";
        else
        {
            cout << "POSSIBLE\n";

            int k = 0;
            long long two = 1;

            memset(X, 0, sizeof(X));

            while(two<=B)
            {
                two*= 2;
                k++;
            }

            two/=2;
            k--;
            k+= 2;

            for(int i=1; i<=k; i++)
                for(int j=i+1; j<=k; j++)
                    X[i][j] = 1;

            for(int i=k; i<N; i++)
                X[i][i+1] = 1;

            B-= two;

            while(B)
            {
                two/= 2;
                k--;

                if(B>=two)
                {
                    B -= two;
                    X[k][N] = 1;
                }
            }

            for(int i=1; i<=N; i++)
            {
                for(int j=1; j<=N; j++)
                    printf("%d", X[i][j]);
                printf("\n");
            }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
