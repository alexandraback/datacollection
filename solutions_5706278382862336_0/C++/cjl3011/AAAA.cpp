#include<functional>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<numeric>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<set>
#include<map>
using namespace std;
int getnum()//读大量数据特别快
{
    char ch;
    while(ch=getchar(),ch==10||ch==32);
    int ans=ch-48;
    while((ch=getchar())!=EOF&&(ch>='0'&&ch<='9'))
    {
        ans*=10;
        ans+=ch-'0';
    }
    return ans;
}
long long gcd(long long a,long long b)
{
    long long r;
    while(b>0)
    {
         r=a%b;
         a=b;
         b=r;
    }
    return a;
}
int main(int argc,char *argv[])
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("Aout","w",stdout);
    int t;
    long long a,b;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%lld/%lld",&a,&b); 
        printf("Case #%d: ",cas);
        if(b%a==0)
        {
            b=b/a;
            long long sum=0;
            while(b%2==0&&b!=0)
            {
                b/=2;
                sum++;
            }
            if(b==1)
                cout<<sum<<endl;
            else
                cout<<"impossible"<<endl;
        }
        else if(a<b)
        {
            long long sum=0;
            while(a<b)
            {
                a*=2;
                sum++;
            }  
            long long r=gcd(a,b);  
            b/=r;
            while(b%2==0&&b!=0)
            {
                b/=2;
            }
            if(b==1)
                cout<<sum<<endl;
            else
                cout<<"impossible"<<endl;
        } 
    }
    return 0;
}

