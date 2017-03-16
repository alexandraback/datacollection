#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int a[1005],b[1005];
int n;
int cnt;
bool donea[1005];
bool doneb[1005];
int main()
{

    freopen("B-large.in","r",stdin);
    freopen("out4.txt","w",stdout);
    int cas=1;
    int t;
    cin>>t;
    while(t--)
    {
        memset(donea,0,sizeof(donea));
        memset(doneb,0,sizeof(doneb));
        cnt=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
        }
        int ans = 0;
        int t = 0;
        int cnt =0;
        while(cnt<n)
        {
            bool flag = false;
            bool f= false;
            int pos = -1;
            int tpos= -1;
            for(int j=0;j<n;j++)
            {
                if(t>=b[j]&&!doneb[j])
                {
                    if(!donea[j])
                    {
                        pos=j;
                        f=1;
                    }
                    else
                    {
                        tpos=j;
                    }
                    flag = true;
                }
            }
            if(flag)
            {
                if(f)
                {
                    ans++;
                    cnt++;
                    doneb[pos]=1;
                    t+=2;
                }
                else
                {
                    ans++;
                    cnt++;
                    doneb[tpos]=1;
                    t++;
                }
                continue;
            }
            pos = -1;
            int small = -1;
            for(int j=0;j<n;j++)
            {
                if(!doneb[j]&&!donea[j]&&t>=a[j])
                {
                    //cout<<"do a "<<j<<endl;
                    if(small<b[j])
                    {
                        small=b[j];
                        pos = j;
                    }
                    flag = 1;
                    //cout<<"t is "<<t<<endl;
                }
            }
            if(!flag)
                break;
            ans++;
            donea[pos]=1;
            t++;
        }
        if(cnt!=n)
            printf("Case #%d: Too Bad\n",cas++);
        else
            printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
