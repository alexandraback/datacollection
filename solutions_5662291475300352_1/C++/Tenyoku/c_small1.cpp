#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int pos[100];
int sp[100];

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas)
    {
        int k, d, h, m;
        int ans;
        scanf("%d\n", &k);
        n=0;
        while(k-->0)
        {
            scanf("%d %d %d", &d, &h, &m);
            for(int i=0; i<h; ++i)
            {
                pos[n+i] = d;
                sp[n+i] = m+i;
            }
            n+=h;
        }
        if(n<=1) ans = 0;
        else
        {
            ans = 0;
            for(int i=0; i<n; ++i)
                for(int j=0; j<n; ++j)
                    if(i!=j)
                    {
                        if(((long long)pos[i]-pos[j]+360)*sp[j] <= ((long long)360-pos[i])*(sp[i]-sp[j]))
                            ans += 1;
                    }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
