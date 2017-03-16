#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

int main()
{
    LL N,i,j,it; cin>>N;
    LL r,c,w;

    for(it=0; it<N; it++)
    {
        cout << "Case #" << it+1 << ": ";
        cin>>r>>c>>w;

        LL ans=c/w*r+w-1;
        if(c%w)
            ans++;

        cout << ans << endl;
    }
    return 0;
}

