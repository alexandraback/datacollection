#include <iostream>
#include <math.h>
#include <cstdio>
#include <algorithm>
using namespace std;

int v[20000];

long long DP[100][100];

int main()
{
    freopen("B-small.in","r",stdin);
    freopen("B-small.out","w",stdout);
    int tc;
    cin >> tc;

    for(int nt=1; nt<=tc; nt++)
    {
        int E, R, N;
        cin >> E >> R >> N;
        for(int i=0; i<N; i++)
            cin >> v[i];

        memset(DP,0x80,sizeof(DP));
        DP[0][E]=0;
        for(int i=0; i<N; i++)
            for(int j=0; j<=E; j++)
                for(int k=0; k<=j; k++)
                    DP[i+1][min(E,j-k+R)]=max(DP[i+1][min(E,j-k+R)],DP[i][j]+k*v[i]);

        long long ans=0;
        for(int i=0; i<=E; i++)
            ans=max(DP[N][i],ans);

        cout << "Case #" << nt << ": " << ans << endl;

    }
}
