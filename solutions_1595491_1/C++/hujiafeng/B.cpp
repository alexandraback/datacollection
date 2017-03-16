#include<iostream>
using namespace std;
int a[105];
int main()
{
    int ca;
    freopen("B-large.in","r",stdin);
    freopen("B.out","w",stdout);
    cin>>ca;
    int t,s,p,tmp;
    for(int k=1;k<=ca;k++)
    {
        int ans=0;
        printf("Case #%d: ",k);
        cin>>t>>s>>p;
        for(int i=0;i<t;i++)
        {
            cin>>a[i];
            tmp=a[i]/3;
            if(a[i]%3==0)
            {
                if(tmp>=p) ans++;
                else if(s>0 && tmp-1>=0 && tmp+1>=p)
                {
                    ans++;s--;
                }
            }else if(a[i]%3==1)
            {
                 if(tmp+1>=p) ans++;
            }else if(a[i]%3==2)
            {
                if(tmp+1>=p) ans++;
                else if(tmp+2>=p && s>0)
                {
                    ans++;
                    s--;
                }
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
