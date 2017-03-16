#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
long long ans[2000001];
bool searched[2000001];
int temp[101];
int pow[]={1,10,100,1000,10000,100000,1000000,10000000};
int n=2000000;
int lowbit(int i)
{
   return i&(-i);
}
void add(long long a[],int i,int v)
{
   while (i<=n)
   {
      a[i]+=v;
      i+=lowbit(i);
   }
}
long long sum(long long a[],int i)
{
   int s=0;
   while (i>0)
   {
      s+=a[i];
      i-=lowbit(i);
   }
   return s;
}
int bit(int num)
{
    int ret = 0;
    while(num)
    {
        ret++;
        num/=10;
    }
    return ret;
}
long long solve(int a,int d)
{
    memset(searched,0,sizeof(searched));
    long long ret = 0;
    for(int i=a;i<=d;i++)
    {
        if(searched[i])
            continue;
        int b = bit(i);
        searched[i]=1;
        int cnt =0;
        temp[cnt++]=i;
        for(int j=1;j<b;j++)
        {
            int t = i/pow[j-1];
            if(t%10==0)
                continue;
            int num = i%pow[j]*pow[b-j]+i/pow[j];
            if(num<a||num>d)
                continue;
            if(!searched[num])
                temp[cnt++]=num;
            searched[num]=1;
        }
        //sort(temp,temp+cnt);
        ret+=cnt*(cnt-1)/2;
    }
    return ret;
}
int main()
{
    //in();
    freopen("C-large.in","r",stdin);
        freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    int cas =1;
    while(t--)
    {

        int a,b;
        cin>>a>>b;
        long long ans = solve(a,b);
        cout<<"Case #"<<cas++<<": "<<ans<<endl;

    }
    return 0;
}
