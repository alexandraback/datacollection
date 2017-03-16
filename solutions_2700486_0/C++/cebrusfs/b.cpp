#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define MAX 2001
using namespace std;

double C[MAX][MAX]; 
double D[MAX][MAX]; 


int N, X, Y;
double solve()
{
    scanf("%d %d %d", &N, &X, &Y);

    int s = 0;
    for(int i=0; s < N ; i++)
    {
        int m = i*2 + 1;

        int n = N - s;

        s += m+m-1;

        //check level
        if(abs(X) + abs(Y) != 2*i)
            continue;

        int k = Y+1;

        if(k > m)
            return 0.0;
        else if(k == m)
            return n >= m+m-1;

        if(n >= m) //one side full
        {
            double ans = 0.0;
            if(n - (m-1) >= k)
                ans += C[n][m-1];

            for(int l=0; l<m-1; l++)
            {
                int r = n - l;
                if(r >= m-1 || r < k)
                    continue;

                ans += C[n][r];
            }
            return ans;
        }
        else
        {
            //printf("%d %d %lf\n", n, k, C[n][k]);
            return D[n][k]; // C(n, t) t >= k
        }
    }
    return 0.0;
}

int main()
{
    int T;
    scanf("%d", &T);

    C[0][0] = 1;
    for(int i=1; i<MAX; i++)
        for(int j=0; j<=i; j++)
            C[i][j] = (C[i-1][j] * 0.5) + (j>0 ? C[i-1][j-1] * 0.5 : 0);
    for(int i=1; i<MAX; i++)
        for(int j=i; j>=0; j--)
            D[i][j] = C[i][j] + (j+1 <= i ? D[i][j+1] : 0);

    for(int Ti=1; Ti<=T; Ti++)
        printf("Case #%d: %lf\n", Ti, solve());
}
