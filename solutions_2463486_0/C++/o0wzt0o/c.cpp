#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
long long n,m,len;
long long a[1000]={
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
2001002
};
int tp;
void init()
{
     int i;
     for(i=0;a[i];i++)
         a[i]=a[i]*a[i];
     tp=i;
}
int main()
{
        long long i;int j,k,tot,ttl;
        cin>>tot;
        init();
        for(ttl=1;ttl<=tot;ttl++)
        {
            cin>>n>>m;
            for(i=0;i<tp;i++)
                if(a[i]>=n)
                    break;
            for(j=0;j<tp;j++)
                if(a[j]>m)
                    break;
            
            printf("Case #%d: %d\n",ttl,j-i);
        }
        
        return 0;
}
