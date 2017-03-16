#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

map<long,int> mp;
int main()
{
    int t,i;
    long a,b,j,count,temp,tmp1,t1,t2,m;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        count=0;
        scanf("%ld %ld",&a,&b);
        temp=a;
        tmp1=1;
        while(temp > 0)
        {
            temp/=10;
            tmp1*=10;
        }
        tmp1/=10;
        t1=tmp1;
        t2=10;
        for(j=a;j<=b;j++)
        {
            mp.clear();
            temp=j;
            t1=tmp1;
            t2=10;
            while(t1>1)
            {
                m=((temp%t2)*t1 + temp/t2);
                
                if((m>temp) && (m<=b) && (mp[m]==0))
                {
                    mp[m]=1;
                    count++;
                }
                t2*=10;
                t1/=10;
            }
        }
        printf("Case #%d: %ld\n",i,count);
    }
}
