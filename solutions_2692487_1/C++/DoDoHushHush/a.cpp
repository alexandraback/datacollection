#include<iostream>
#include<algorithm>
using namespace std;

long long x[1000010];
long long n;

long long min(long long a,long long b)
{
    if(a>b)return b;
    else return a;
}
long long aaa(long long least,long long mv,long long ms,long long h)
{
    //cout<<least<<" "<<mv<<" "<<ms<<" "<<h<<endl;
    if(least!=-1&&mv>=least)return least;
    if(h==n+1)return mv;

    if(ms>x[h])
    {
        return aaa(least,mv,ms+x[h],h+1);
    }
    else
    {
        if (ms-1==0)return mv+(n+1-h);
        if(least!=-1)return aaa(min(mv+(n+1-h),least),mv+1,ms+(ms-1),h);
        else return aaa(mv+(n+1-h),mv+1,ms+(ms-1),h);
    }
}
bool cmp(long long a,long long b)
{
    return (a<b);
}
int main()
{
long long t;
cin>>t;
for(long long tt=1;tt<=t;tt++)
{

cin>>x[0]>>n;
for(long long i=1;i<=n;i++)cin>>x[i];
sort(x+1,x+1+n,cmp);

cout<<"Case #"<<tt<<": "<<aaa(-1,0,x[0],1)<<endl;

}
return 0;
}
