#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int pos[2];
int sp[2];

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
            if(pos[1] < pos[0] || (pos[1]==pos[0]&&sp[1]>sp[0]))
            {
                swap(pos[0], pos[1]);
                swap(sp[0], sp[1]);
            }
            if(((long long)pos[0]-pos[1]+360)*sp[1] <= ((long long)360-pos[0])*(sp[0]-sp[1]))
                ans = 1;
            else if(((long long)pos[1]-pos[0]+360)*sp[0] <= ((long long)360-pos[1])*(sp[1]-sp[0]))
                ans = 1;
            else ans = 0;
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
