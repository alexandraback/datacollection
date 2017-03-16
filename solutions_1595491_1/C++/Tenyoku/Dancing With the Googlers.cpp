#include <cstdio>
using namespace std;

int n, s, p;
int list[100];

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("Dancing With the Googlers.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; ++i)
    {
        scanf("%d %d %d", &n, &s, &p);
        for(int i=0; i<n; ++i) scanf("%d", &list[i]);
        int ans = 0;
        for(int i=0; i<n; ++i)
        {
            if((list[i]+2)/3 >= p) ++ans;
            else if(s>0)
                if(list[i]>=2 && (list[i]+4)/3 >= p)
                {
                    ++ans;
                    --s;
                }
        }
        printf("Case #%d: %d\n", i, ans);
    }
}
