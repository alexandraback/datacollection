#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
#include <numeric>
#include <sstream>
#include <stack>
#include <map>
#include <queue>

#define CL(arr, val)    memset(arr, val, sizeof(arr))

#define lc l,m,rt<<1
#define rc m + 1,r,rt<<1|1
#define pi acos(-1.0)
#define ll __int64
#define L(x)    (x) << 1
#define R(x)    (x) << 1 | 1
#define MID(l, r)   (l + r) >> 1
#define Min(x, y)   (x) < (y) ? (x) : (y)
#define Max(x, y)   (x) < (y) ? (y) : (x)
#define E(x)        (1 << (x))
#define iabs(x)     (x) < 0 ? -(x) : (x)
#define OUT(x)  printf("%I64d\n", x)
#define lowbit(x)   (x)&(-x)
#define Read()  freopen("C-large-1.in", "r", stdin)
#define Write() freopen("dout.txt", "w", stdout);
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)

#define M 137
#define N 22

using namespace std;


int a[100] = {
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
10000001
};
int no[10000100];

int main()
{
   Read();
   Write();
   int i;
   CL(no,0);
   for (i = 0; i <= 100; ++i)
   {
       if (a[i] == 0) break;
       no[a[i]] = 1;
   }
   for (i = 1; i < 10000100; ++i) no[i] += no[i - 1];

   int T,cas = 1;
   ll l,r;
   scanf("%d",&T);
   while (T--)
   {
       cin>>l>>r;
       double ttl = sqrt(l);
//       cout<<ttl<<endl;
       int tl = 0;
       int tr = sqrt(r);
       if (ttl == (int)ttl)
       {
           tl = (int)ttl - 1;
       }
       else tl = (int)ttl;
//       printf("%d %d\n",tl,tr);
       printf("Case #%d: ",cas++);
       cout<<no[tr] - no[tl]<<endl;
   }
   return 0;
}
