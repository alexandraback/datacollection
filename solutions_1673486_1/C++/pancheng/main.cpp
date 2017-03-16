#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

#define MAX 100010

using namespace std;

int A,B;
double p[MAX];
double cp[MAX];

double solve()
{
    double sta1=0, sta2=MAX, sta3=0;
    double pb=1;
    for( int i=0; i!=A; i++)
        pb *= p[i];
    sta1 = pb*(B-A+1) + (1-pb)*(2*B-A+2);

    cp[0] = 1;
    for( int i=1; i<=A; i++)
        cp[i] = cp[i-1]*p[i-1];

    double m = 1e7;
    for( int k=1; k<=A; k++)
    {
        double temp = cp[A-k]*(2*k+B-A+1)+(1-cp[A-k])*(2*B+2*k-A+2);
        if( temp<m )
            m = temp;
    }
    sta2 = m;


    sta3 = B+2;
    return min(min(sta1,sta2),sta3);
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;

    cin>>T;
    for( int i=0; i!=T; i++)
    {
        memset(p,0,MAX*sizeof(double));
        memset(cp,0,MAX*sizeof(double));
        cin>>A>>B;
        for( int j=0; j!=A; j++)
            cin>>p[j];
        printf("Case #%d: %.6f\n",i+1,solve());
    }
    return 0;
}
