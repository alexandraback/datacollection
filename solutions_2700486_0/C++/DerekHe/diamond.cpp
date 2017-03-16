#include <iostream>
#include <iomanip>
using namespace std;

int Z[1000005], Zn;

void init()
{
    for (Zn=1;true;Zn++)
    {
        Z[Zn-1] = Zn*(2*Zn-1);
        if (Z[Zn-1]>100001)
            return;
    }
}

int abs(int x)
{
    if (x<0) return -x;
    return x;
}

int N, X, Y, Batch;
double a[800][800];

void real_main()
{
    cin>>N>>X>>Y;
    for (Batch=0;Batch<Zn;Batch++)
        if (Z[Batch]<=N && N<=Z[Batch+1])
            break;
    if ((abs(X)+abs(Y))/2<=Batch)
    {
        cout<<"1.0"<<endl;
        return;
    }
    if ((abs(X)+abs(Y))/2>Batch+1)
    {
        cout<<"0.0"<<endl;
        return;
    }
    N -= Z[Batch];
    int numBatch = Z[Batch+1]-Z[Batch];
    int totalNum = (numBatch+1)/2;
    
    if (N == numBatch) {cout<<"1.0"<<endl;return;}
    if (Y == totalNum-1)
    {
        if (N == numBatch)
            cout<<"1.0"<<endl;
        else
            cout<<"0.0"<<endl;
        return;
    }

    for (int i=0;i<800;i++)
        for (int j=0;j<800;j++)
            a[i][j]=0.0;
    a[0][0] = 1.0;
    for (int i=1;i<=N;i++)
    {
        a[i][0]=1.0;
        for (int j=1;j<=i;j++)
            a[i][j] = a[i-1][j-1]+a[i-1][j];
    }

    double S0 = 0.0, S1 = 0.0;
    for (int i = 0; i<=N;i++)
    {
        if (i>totalNum-1 || N-i > totalNum-1)
            continue;
        S0+=a[N][i];
        if (i>Y)
            S1+=a[N][i];
    }
    cout<<setprecision(10)<<S1/S0<<endl;
    
    /*
    for (int i=1;i<=N;i++)
    {
        a[i][0] = 1.0;
        for (int j=1;j<=Y+1;j++)
        {
            if (a[i-1][j-1]!=0.0)
            a[i][j]=a[i-1][j]+(1-a[i-1][j]/a[i-1][j-1])*0.5*a[i-1][j-1];
            if (i>totalNum-1)
                          {
                                               a[i][j] *= (1-a[i-1][totalNum-1]);
                                                                if (i-(totalNum-1)>=j)
                                                                                         a[i][j] += a[i-1][totalNum-1];
                                                                             }

        }
    }
    cout<<setprecision(10)<<a[N][Y+1]<<endl;*/
}

int main()
{
    init();
    Zn--;
    int T; cin>>T;
    for (int i=1;i<=T;i++)
    {
        cout<<"Case #"<<i<<": ";
        real_main();
    }
    return 0;
}
