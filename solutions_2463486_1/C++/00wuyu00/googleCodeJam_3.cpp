#include<iostream>
#include<stdio.h>
#include<math.h>
#include<sstream>
using namespace std;
long long c[41]={0,
1,
4,
9,
121,
484,
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001,
102030201,
104060401,
121242121,
123454321,
125686521,
400080004,
404090404,
10000200001,
10221412201,
12102420121,
12345654321,
40000800004,
1000002000001,
1002003002001,
1004006004001,
1020304030201,
1022325232201,
1024348434201,
1210024200121,
1212225222121,
1214428244121,
1232346432321,
1234567654321,
4000008000004,
4004009004004,
100000020000001};
long long a,b;
int main()
{
   freopen("C-large-1.in","r",stdin);
   freopen("output.out","w",stdout);
   int t;
   scanf("%d",&t);
   for(int j=0;j<t;j++)
   {
    scanf("%lld%lld",&a,&b);
    int i,k;
    for(i=0;i<41;i++)
        if(c[i]>=a) break;
    for(k=0;k<41;k++)
        if(c[k]>b) break;
    printf("Case #%d: %d\n",j+1,k-i);
   }
   return 0;
}
