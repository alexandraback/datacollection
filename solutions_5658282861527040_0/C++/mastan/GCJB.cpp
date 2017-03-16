#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    freopen("D:/in.txt","r",stdin);
    freopen("D:/out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for (int itr=1; itr<=tc; itr++)
    {
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        if (a>b)
            swap(a,b);
        int ret=0;
        for (int i=0; i<a; i++)
            for (int j=0; j<b; j++)
                ret+=(i&j)<k;
        printf("Case #%d: %d\n",itr,ret);
    }
}
