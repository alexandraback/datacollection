/*
Original Author: El_Magnifico(Sudhanshu Shekhar)
*/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<sstream>
#include<cmath>
#include<list>
#include<climits>
#include<stack>
#include<map>
#include<bitset>
#include<queue>
#include<set>
#include<climits>
#include<cstring>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
typedef long long ll;

int main()
{
    freopen("C:\\Users\\Psyduck\\Desktop\\C-large-1.in","r",stdin);
    freopen("C:\\Users\\Psyduck\\Desktop\\output.txt","w",stdout);
    ll i,j,k,n,m,t,tcase,a,b,count=0;
    ll arr[]={1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002};
    scanf("%lld",&tcase);
    for(t=1;t<=tcase;t++)
    {
        printf("Case #%lld: ",t);
        scanf("%lld %lld",&a,&b);
        count=0;
        a=(int)(ceil(sqrt(a)));
        b=(int)(floor(sqrt(b)));
        //cout<<a<<" "<<b<<endl;
        for(i=0;i<39;i++)
        {
            if(arr[i]>=a && arr[i]<=b)count++;
        }
        printf("%lld\n",count);
    }
    return 0;
}
