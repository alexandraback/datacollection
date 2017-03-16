#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long T,i,r,t,L,R;
int main()
{
    //freopen("2.in","r",stdin);
    //freopen("2.out","w",stdout);
    cin >> T;
    for (i=0;i<T;i++)
    {
        cin >> r >> t;
        L=0;
        R=10000000000;
        while (L < R)
        {
            long long m = (L + R) / 2;
            //cout << ((2*r+1)+(m-1)*2) << "  " << t/m << " " << m << endl;
            if ((long long)(2*r+1)+(m-1)*2 <= (long long)t/m)
                L = m + 1;
            else {
                R = m;
            }
        }
        cout << "Case #" << i+1 << ": " << L-1 << endl;
    }
    return 0;
}

