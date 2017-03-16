#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;
const int N = 10001;
char cmd[N];
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out","w",stdout);
    int t ,cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        int A , B ,ans = 0;
        scanf("%d %d",&A,&B);
        for (int i = A; i < B ; i++)
        {
            int left = i % 10;
            int right = i / 10;
            int base = 1 , tmp = i ,start = 10 , len = 0;
            set<int> st;
            while(tmp)
            {
                base *= 10;
                tmp /= 10;
                len ++;
            }
            base /= 10;
            while(right)
            {
                int ns = left * base + right , nlen = 0,ntmp = ns;
                while(ntmp)
                {
                    ntmp/=10;
                    nlen ++;
                }
                base /= 10;
                left = left + start * (right % 10);
                start *= 10;
                right /= 10;
                if(ns > i && ns <= B && nlen == len && st.count(ns) == 0)
                {
                    ans ++;
                    st.insert(ns);
                }
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }

    return 0;
}
