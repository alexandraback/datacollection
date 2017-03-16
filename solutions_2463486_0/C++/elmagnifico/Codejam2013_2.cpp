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

bool ispalindrome(ll x)
{
    if((x/10)==0)return true;
    ll i,b,num=0,savex;
    savex=x;
    while(x>0)
    {
        num=(num*10)+(x%10);
        x/=10;
    }
    if(num==savex)return true;
    return false;
}

int main()
{
    freopen("C:\\Users\\Psyduck\\Desktop\\C-small-attempt0.in","r",stdin);
    freopen("C:\\Users\\Psyduck\\Desktop\\output.txt","w",stdout);
    ll i,j,k,n,m,t,tcase,count,a,b;
    scanf("%lld",&tcase);
    for(t=1;t<=tcase;t++)
    {
        scanf("%lld %lld",&a,&b);
        count=0;
        printf("Case #%lld: ",t);
        a=(int)(ceil(sqrt(a)));
        b=(int)(floor(sqrt(b)));
        //cout<<a<<" "<<b<<endl;
        for(i=a;i<=b;i++)
        {
            if(ispalindrome(i) && ispalindrome(i*i))
            {
                //cout<<"Ans="<<i<<endl;
                count++;
            }
        }
        printf("%lld\n",count);
    }
    return 0;
}
