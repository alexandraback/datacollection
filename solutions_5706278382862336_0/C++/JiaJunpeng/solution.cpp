#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;
long long a[2],d;
char str[1101];
int ans,gen;
long long gcd(long long a,long long b)
{
     long long temp;
     while(b!=0)
     {
        temp=a%b;
        a=b;
        b=temp;
     }
     return a;
}
int main()
{
    int cc,len,t,i,j,s,p,q,tst=0;
     freopen("debug\\input.txt","r",stdin);
    freopen("debug\\output.txt","w",stdout);
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        tst++;
        gets(str);
        len=strlen(str);
        a[0]=a[1]=0;
        cc=0;
        for(i=0;i<len;i++)
        {
            if(str[i]>='0'&&str[i]<='9')
               a[cc]=(long long)10*a[cc]+str[i]-'0';
            else
               cc++;
        }
        printf("Case #%d: ",tst);
        d=gcd(a[0],a[1]);
      //  printf("a[0]=%I64d,a[1]=%I64d\n",a[0],a[1]);
        a[0]/=d;
        a[1]/=d;
        d=a[1];
        gen=0;
        while(d%2==0)
        {
            d/=2;
            gen++;
        }
      //  printf("d=%I64d,gen=%d\n",d,gen);
        if(d!=1||gen>40)
           puts("impossible");
        else
        {
            ans=0;
            while(a[0]<a[1])
            {
                a[0]<<=(long long)1;
                ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
