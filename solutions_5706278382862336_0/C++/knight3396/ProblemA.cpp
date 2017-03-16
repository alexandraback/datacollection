#include <iostream>
#include <stdio.h>
using namespace std;

long long unsigned A, B;
long long unsigned common;
int times = 0;
int gennum = -1;

bool Gen()
{
    if(A == B)
    {
        if(gennum < 0)
            gennum = times;
        return true;
    }
    while( A > B)
    {
        A -= B;
        if(gennum < 0)
            gennum = times;
    }
    long long unsigned m, n, t;
    t = A;  m = B;  n = A;
    while (m % n != 0)
    {
        t=m%n;   m=n;   n=t;
    }
    A /= n; B /= n;
    while (A < B)
    {
        A = A << 1;
        times++;
    }
    if(times >= 40)
        return false;
    return Gen();
}

int main()
{
    int _T, idx = 0;
    cin >> _T;
    while(idx < _T)
    {
        idx++;
        scanf("%d/%d", &A, &B);
        times = 0;  gennum = -1;
        cout << "Case #" << idx << ": ";
        if(Gen())
            cout << gennum;
        else
            cout << "impossible";
        // output result
        cout << endl;
    }
    return 0;
}