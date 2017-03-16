#include <iostream>
using namespace std;

int E, R, N;
int spd[100][100];
int v[100];

int min(int a, int b)
{
    if (a<b) return a;
    return b;
}

void real_main()
{
    cin >>E>>R>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>v[i];
    }
    memset(spd, 0x00, sizeof spd);
    for (int i = N-1; i>=0; i--)
    {
        for (int j = R; j<=E; j++)
        {
            for (int k = 0; k<=j;k++)
                if (spd[i][j]<spd[i+1][min(E, j-k+R)]+v[i]*k)
                    spd[i][j] = spd[i+1][min(E, j-k+R)]+v[i]*k;
        }
    }
    cout<<spd[0][E]<<endl;
}

int main()
{
    int T; cin>>T;
    for (int i=1;i<=T;i++)
    {
        cout<<"Case #"<<i<<": ";
        real_main();
    }
    return 0;
}
