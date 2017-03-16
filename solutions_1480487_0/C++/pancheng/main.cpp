#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

#define MAX 100010

using namespace std;

int N;
int s[210];
double d[210];

void solve()
{
    double sum=0;
    for(int i=0; i!=N; i++)
        sum += s[i];
    double avg = 2*sum/(double)N;
    double sum2 = 0;
    int c2 = 0;
    for( int i=0; i!=N; i++)
    {
        if( s[i]<avg )
        {
            sum2 += s[i];
            c2++;
        }
    }
    double avg2 = (sum+sum2)/(double)c2;
    for( int i=0; i!=N; i++)
    {
        if( s[i]>=avg2 )
            d[i] = 0;
        else
            d[i] = (avg2-(double)s[i])/(double)sum;
    }
}
int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    //freopen("data.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin>>T;

    for( int t=0; t!=T; t++)
    {
        cin>>N;
        for( int i=0; i!=N; i++)
        {
            cin>>s[i];
        }
        solve();
        printf("Case #%d:",t+1);
        for( int i=0; i!=N; i++)
            printf(" %0.6f", max(0.0,d[i]*100));
        cout<<endl;
    }

    return 0;
}
