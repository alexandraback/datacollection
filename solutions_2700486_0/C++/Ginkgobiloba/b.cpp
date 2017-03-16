#include <iostream>
#include <cstdio>
using namespace std;

long long getLayer(long long x, long long y)
{
    if(x<0) x=-x;
    return (x+y)/2;
}

long long getMinimum(long long layer)
{
    return layer + layer*(layer-1)*4/2 + 1;
}

long long getMaximum(long long layer)
{
    ++layer;
    return layer + layer*(layer-1)*4/2;
}

double calculate(long long n, long long x, long long y)
{
    long long layer=getLayer(x, y);
    long long minimum=getMinimum(layer);
    long long maximum=getMaximum(layer);
    //cout<<minimum<<" "<<maximum<<endl;
    if(n<minimum) return 0.0;
    if(n>=maximum) return 1.0;
    long long have = n - minimum + 1;
    long long need = y + 1;
    if(need==layer+2) return 0.0;
    if(have<need) return 0.0;
    double ans=0.0, base=1.0;
    long long remains = have;
    //cout<<have<<" "<<need<<endl;
    for(long long i=(have); i>=need; --i)
    {
        /*while(base>1e6 && remains)
        {
            base/=2.0;
            --remains;
        }*/
        /*while(remains && (base>1e8 || ans>1e8))
        {
            ans/=2.0;
            base/=2.0;
            --remains;
        }*/
        //if(i<=layer+1)
            ans+=base;
        //cout<<ans<<endl;
        //long long a=have-i;
        //if(!a) a=1;
        //long long b=i-1;
        //if(!b) b=1;
        //if(i==have)
        //    base=base*i/((i-1)*(have-i+1));
        //else
        base=base*i/(have-i+1);
    }
    base=1.0;
    for(long long i=(have); i>=layer+1; --i)
    {
        if(have-i>=need)
            ans+=base;
        base=base*i/(have-i+1);
    }
    while(remains)
    {
        ans/=2.0;
        --remains;
    }
    return ans;
}

int main()
{
    int numOfCases;
    long long n, x, y;
    cin>>numOfCases;
    for(int i=1; i<=numOfCases; ++i)
    {
        cin>>n>>x>>y;
        //cout<<"Case #"<<i<<": "<<calculate(n, x, y)<<endl;
        printf("Case #%d: %.10f\n", i, calculate(n, x, y));
    }
    return 0;
}
