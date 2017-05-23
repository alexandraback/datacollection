#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

long long num[49] =
{
0,
1,
2,
3,
11,
22,
101,
111,
121,
202,
212,
1001,
1111,
2002,
10001,
10101,
10201,
11011,
11111,
11211,
20002,
20102,
100001,
101101,
110011,
111111,
200002,
1000001,
1001001,
1002001,
1010101,
1011101,
1012101,
1100011,
1101011,
1102011,
1110111,
1111111,
2000002,
2001002,
10000001,
10011001,
10100101,
10111101,
11000011,
11011011,
11100111,
11111111,
20000002
}
;

int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("C-large-1.out","w",stdout);
    int i,n,ca = 1;
    long long s,e;
    int ans1,ans2;
    bool f1,f2;
    scanf("%d",&n);
    while(n--)
    {
        cin >> s >> e;
        f1 = f2 = 0;
        ans1 = ans2 = 0;
        for( i = 0; i < 49; ++i)
        {
            if(num[i] * num[i] > s) 
            {
                ans1 = i;
                break;
            }
            else if(num[i] * num[i] == s) 
            {
                ans1 = i;
                f1 = 1;
                break;
            }
        }
        for( i = 0; i < 49; ++i)
        {
            if(num[i] * num[i] > e) 
            {
                ans2 = i;
                break;
            }
            if(num[i] * num[i] == e) 
            {
                ans2 = i;
                f2 = 1;
                break;
            }
        }
        printf("Case #%d: ",ca++);
        if(!f1 && !f2)printf("%d\n",ans2 - ans1);
        else if(f1 && f2) printf("%d\n",ans2 - ans1 + 1);
        else if(f1 && !f2) printf("%d\n",ans2 - ans1);
        else if(!f1 && f2) printf("%d\n",ans2 - ans1 + 1);
    }
    return 0;
}










