#include<bits/stdc++.h>
using namespace std;
int ret[1000100];
int nCases;
int rev (int n)
{
    int rt=0;
    while(n)
    {
        rt*=10;
        rt+=n%10;
        n/=10;
    }
    return rt;
}
void fillRet ()
{
    ret[1] = 1;
    for(int i=1;i<=1000000;i++)
    {
        ret[i+1] = min(ret[i]+1,ret[i+1]);
        ret[rev(i)] = min (ret[i]+1,ret[rev(i)]);
    }
}
int main (void)
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    memset(ret,1,sizeof(ret));
    fillRet();
    //cout<<ret[0]<<endl;
    cin>>nCases;
    int ac;
    for(int aCase = 1;aCase <= nCases;aCase++)
    {
        cin>>ac;
        cout<<"Case #"<<aCase<<": "<<ret[ac]<<endl;
    }
    return 0;
}
