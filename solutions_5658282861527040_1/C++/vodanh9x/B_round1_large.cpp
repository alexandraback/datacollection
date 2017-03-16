#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
using namespace std;
#define length(x) (int)x.size()
const double pi=acos(-1);

int a[100], b[100],c[100];
long long f[100][4][4][4];

long long tinhtoan(int n, int kt1, int kt2, int kt3)
{
    if (n == 30)
    {
        f[n][kt1][kt2][kt3] = 1; return 1;
    }
    if (f[n][kt1][kt2][kt3]>=0) return f[n][kt1][kt2][kt3];
    long long sum = 0;
    int x1, x2;
    if (kt1 == 1) x1 = 1; else x1 = a[n+1];
    if (kt2 == 1) x2 = 1; else x2 = b[n+1];
    for(int i=0; i<=x1; i++)
        for(int j=0; j<=x2; j++)
    {
        int kt11, kt22, kt33;
        kt11 = kt1; kt22 = kt2; kt33 = kt3;
        if ((kt1 == 0) && (i < a[n+1])) kt11 = 1;
        if ((kt2 == 0) && (j < b[n+1])) kt22 = 1;
        if ((kt3 == 0) && ((i&j)>c[n+1])) continue;
        if ((kt3 == 0) && ((i&j)<c[n+1])) kt33 = 1;
        sum = sum + tinhtoan(n+1, kt11, kt22, kt33);
    }
    f[n][kt1][kt2][kt3] = sum;
    return sum;
}

void xuli()
{
    int A, B, K;
    cin>>A>>B>>K;
    A--; B--; K--;
    int n = 30;
    while (n>0)
    {
        a[n] = A % 2; b[n] = B % 2; c[n] = K % 2;
        A /= 2; B /= 2; K /= 2;
        n--;
    }
    for(int i=0; i<=30; i++)
        for(int x1=0; x1<=1; x1++)
            for(int x2=0; x2<=1; x2++)
                for(int x3=0; x3<=1; x3++)
                    f[i][x1][x2][x3] = -1;

    cout<<tinhtoan(0, 0, 0, 0)<<endl;
}

int main()
{
     freopen("input.inp","r",stdin);
     freopen("output.out","w",stdout);
     int test;
     cin>>test;
     for(int t=1; t<=test; t++)
     {
         cout<<"Case #"<<t<<": ";
         xuli();
     }
     return 0;
}
