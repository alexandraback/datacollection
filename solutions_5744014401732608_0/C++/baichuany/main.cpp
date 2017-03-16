#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool p[191];
int plist[191];
int pn;
pair<double,int> arr[(1<<21)+10];
int an;
const long long mod = 1e16;
void init()
{
    pn=0;
    for(int i=2;i<=190;i++)
    {
        if(!p[i])
        {
            plist[pn++]=i;
            for(int j=i*i;j<=190;j+=i)
            {
                p[j]=1;
            }
        }
    }
//    pn=22;
    cout<<pn<<endl;
}
int main()
{
    init();
    an=0;
    for(int i=0;i<(1<<(pn/2));i++)
    {
        double val=0;
        for(int j=0;j<pn/2;j++)
        {
            if((i&(1<<j))==0)val-=log(1.0*plist[j]);
            else val+=log(1.0*plist[j]);
        }
        arr[an++]=make_pair(val,i);
    }
    sort(arr,arr+an);
    double ansv=-100000000;
    long long ansi=0;
    for(int i=0;i<(1<<(pn/2));i++)
    {
        double val=0;
        for(int j=0;j<pn/2;j++)
        {
            if((i&(1<<j))==0)val-=log(1.0*plist[j+pn/2]);
            else val+=log(1.0*plist[j+pn/2]);
        }
        int l=0,r=an-1;
        int tmp=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(val+arr[mid].first<0)
            {
                l=mid+1;
                tmp=mid;
            }
            else r=mid-1;
        }
        if(tmp>=0)
        {
            if(ansv<arr[tmp].first+val)
            {
                ansv=arr[tmp].first+val;
                ansi=((1ll*i)<<(pn/2))+arr[tmp].second;
                cout<<i<<' '<<arr[tmp].second<<endl;
                cout<<ansi<<endl;
            }
        }
    }
    long long output=1;
    for(int i=0;i<pn;i++)
    {
        if((ansi&(1ll<<(i)))!=0)
        {
            output = (output * plist[i]) % mod;
        }
    }

    cout<<output<<endl;
    return 0;
}
