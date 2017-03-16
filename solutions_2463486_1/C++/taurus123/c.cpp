#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[41]={
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
2001002,10000001
};
int main()
{
    int T,ans;
    long long b,c;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%lld%lld",&b,&c);
        b=ceil(sqrt(b));
        c=sqrt(c);
        for(int i=0;i<41;i++)
            if(a[i]>=b){ans=i;break;}
        for(int i=0;i<41;i++)
            if(a[i]>c){ans=i-ans;break;}
        printf("Case #%d: %d\n",cas,ans);
    }
}
