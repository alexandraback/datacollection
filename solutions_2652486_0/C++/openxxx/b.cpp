#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int f[100],cnt=0;
int a[100],b[100],c[100];

int main()
{
    //freopen("C-small-1-attempt0.in","r",stdin);
    //freopen("C-small-1-attempt0.out","w",stdout);
    for(int i=2;i<=5;i++)
    {
        for(int j=i;j<=5;j++)
        {
            for(int k=j;k<=5;k++)
            {
                cnt++;
                f[cnt]=i*j*k;
                a[cnt]=i;
                b[cnt]=j;
                c[cnt]=k;
            }
        }
    }
    int T,R,N,M,K,mm,pro;
    cin>>T;
    cin>>R>>N>>M>>K;
    cout<<"Case #1:"<<endl;
    for(int i=1;i<=R;i++)
    {
        mm=1;
        for(int j=1;j<=K;j++)
        {
            cin>>pro;
            mm=max(mm,pro);
        }
        bool ch=true;
        for(int j=1;j<=cnt;j++)
        {
            if(f[j]==mm)
            {
                ch=false;
                cout<<a[j]<<b[j]<<c[j]<<endl;
                break;
            }
        }
        if(ch)
        {
            cout<<"222"<<endl;
        }
    }
    return 0;
}
















































