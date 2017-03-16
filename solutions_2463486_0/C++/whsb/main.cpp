#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int len;
long long num[40000];//<20000的前缀构造回文数
int len2;
long long biao[40000];

long long make_anum1(long long x)
{
    long long y=x;
    while(x!=0)
    {
        y=y*10+x%10;
        x/=10;
    }
    return y;
}
long long make_anum2(long long x)
{
    long long y=x;
    x/=10;
    while(x!=0)
    {
        y=y*10+x%10;
        x/=10;
    }
    return y;
}

void init()
{
    len=0;
    for(int i=1;i<10000;i++)
    {
        num[len++]=make_anum1(i);
        num[len++]=make_anum2(i);
    }
    sort(num,num+len);
    //for(int i=0;i<len;i++)
    //cout<<num[i]<<endl;
}

bool judge(long long x)
{
    long long z=x,y=0;
    while(x!=0)
    {
        y=y*10+x%10;
        x/=10;
    }
    return z==y;
}

void init2()
{
    len2=0;
    long long tmp;
    for(int i=0;i<len;i++)
    {
        tmp=num[i]*num[i];
        if(judge(tmp))
        {
            biao[len2++]=tmp;
        }
    }
    //for(int i=0;i<len2;i++) cout<<biao[i]<<endl;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    init();
    init2();
    int T;
    long long A,B,ans;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        cin>>A>>B;
        ans=0;
        //if(A>B) swap(A,B);
        for(int i=0;i<len2;i++)
        {
            if(A<=biao[i]&&B>=biao[i]) ans++;
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
