#include <iostream>
#include <math.h>
#include <cstdio>
#include <algorithm>
using namespace std;
#define _USE_MATH_DEFINES

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int tc;
    cin >> tc;

    for(int nt=1; nt<=tc; nt++)
    {
        long long r, t;
        cin >> r >> t;
        long long k=sqrt(t);
        int top=min(k,t/r)+2, bot=1, mid=(top+bot)/2;
        while(top-bot>1)
        {
            long long cov=mid*(2LL*r+1LL)+2LL*mid*(mid-1LL);
            if(cov>t)
                top=mid;
            else
                bot=mid;

            mid=(top+bot)/2;
        }
        cout << "Case #" << nt << ": " << bot << endl;
    }
}
