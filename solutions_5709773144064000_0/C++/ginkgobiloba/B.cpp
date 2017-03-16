#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double calculate(double c, double f, double x)
{
    double t = x /c - 2 / f;
    int n = floor(t);
    if(n<=0) return x/2;
    double a = 0.0;
    for(int i=0; i<n; ++i)
        a += c/(2+i*f);
    a += x/(2+n*f);
    return a;
}

int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; ++i)
    {
        double c, f, x;
        cin>>c>>f>>x;
        printf("Case #%d: %.7f\n", i, calculate(c, f, x));
    }
    return 0;
}
