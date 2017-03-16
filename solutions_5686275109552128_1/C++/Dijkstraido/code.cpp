
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main()
{
    int T,D,maxi,lo,hi,mid,ntest=1;
    vi v;
    scanf("%d\n",&T);
    while(T--)
    {
        scanf("%d\n",&D);
        v = vi(D);
        maxi = 0;
        for(int i = 0; i < D; i++)
        {
            scanf("%d",&v[i]);
            maxi = max(maxi, v[i]);    
        }
        lo = 1; hi = maxi;
        while(lo <= hi)
        {
            mid = (lo + hi) * 0.5;
            bool ok = false;
            for(int dim = 1; dim <= mid && !ok; dim++)
            {
                int cort = mid - dim;
                int cont = 0;
                for(int i = 0; i < D; i++)
                    cont += ceil(v[i] * 1.0 / dim) - 1;

                if(cont + dim <= mid)
                    ok = true;
            }
            
            if(ok)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        printf("Case #%d: %d\n",ntest++,lo);
    }
    return 0;
}
