#include <iostream>
#include <cstdio>
using namespace std;

long long n, boq, r;

bool check (double k)
{
    //cout << k << " " << (2*r + 1) + 2*(k-1)<<" " <<  boq << endl;
    return k*((2*r + 1) + 2*(k-1)) <= boq;
    
    //return 2*r+1 + 2*r+1 + 
}


long long solve ()
{
    cin >> r >> boq; 
    
    
    long long f = 1, l = 2.0*1e18+2; 
    
    while (f < l)
    {
        long long mid = f + (l - f)/2;
        if (check(mid)) f = mid + 1; 
        else l = mid;
    }
    
    return f - 1; 
}

int main ()
{
    int t;
    scanf ("%d", &t);
    
    int i ;
    for (i = 0; i < t; i ++)
    {
        printf ("Case #%d: %lld\n", i+1, solve());
    }
    
    
    return 0;
}