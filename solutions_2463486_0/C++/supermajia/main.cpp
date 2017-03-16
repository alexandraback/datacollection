#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
long long ans[55];
bool ispan(long long a)
{
    string str="";
    while(a)
    {
        int t=a%10;
        str+='0'+t;
        a/=10;
    }
    int l = str.size();
    for(int i=0;i<l;i++)
    {
        if(str[i]!=str[l-1-i])
            return 0;
    }
    return 1;
}
int cnt;
void generate()
{
    for(long long i=1;i<=10000000ll;i++)
    {
        if(!ispan(i))
            continue;
        if(ispan(i*i))
        {
            //cout<<i*i<<endl;
            ans[cnt++]=i*i;
        }
    }
    //cout<<cnt<<endl;
}
long long a;
long long low,high;
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    generate();
    int t;
    int cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int ret=0;
        scanf("%lld%lld",&low,&high);
        for(int i=0;i<cnt;i++)
        {
            if(ans[i]>=low&&ans[i]<=high)
                ret++;
        }
        printf("Case #%d: %d\n",cas++,ret);
    }
    return 0;
}
